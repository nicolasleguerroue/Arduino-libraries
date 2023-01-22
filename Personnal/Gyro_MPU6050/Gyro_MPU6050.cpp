/**
 * @file Gyro_MPU6050.cpp 
 * @author Nicolas LE GUERROUE (nicolasleguerroue@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-11-29
 * 
 * @copyright 
 * 
 */
#include "Arduino.h"
#include "Gyro_MPU6050.h"

Gyro_MPU6050::Gyro_MPU6050(uint8_t address)
{
  _address = address;

}

void Gyro_MPU6050::begin() {


    Wire.begin();
    Wire.beginTransmission(_address);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);
 
}//End begin

void Gyro_MPU6050::getAccelerations(float *ax, float *ay, float *az)
{

  
}


void Gyro_MPU6050::getGyroSpeeds(float *gx, float *gy, float *gz, GyroSpeed gyroSpeed)
{
  
}


void Gyro_MPU6050::computeAngle()
{
  double x = GyAccTemp[0];
  double y = GyAccTemp[1];
  double z = GyAccTemp[2];

  PitchRoll[0] = atan(x/sqrt((y*y) + (z*z))); //  pitch 
  PitchRoll[1] = atan(y/sqrt((x*x) + (z*z))); // roll
  PitchRoll[2] = atan(z/sqrt((x*x) + (y*y))); // pitch
  
  //Conversion Radian en degré
  PitchRoll[0] = PitchRoll[0] * (180.0/pi);
  PitchRoll[1] = PitchRoll[1] * (180.0/pi) ;
  PitchRoll[2] = PitchRoll[2] * (180.0/pi) ;
}

void Gyro_MPU6050::readMPU6050()
{

  Wire.beginTransmission(_address);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(_address,14,true);

  for  (int i=0;i<7;i++)
  {
    if(i!=3)
    {
      GyAccTemp[i]=(Wire.read()<<8|Wire.read()) + GATCorr[i];
    }
    else
    {
      GyAccTemp[i]=(Wire.read()<<8|Wire.read()) + GATCorr[i];
      GyAccTemp[i] = GyAccTemp[i]/340 + 36.53;
    }
  }

  this->computeAngle();
          
  _roll = PitchRoll[0];
  _pitch = PitchRoll[1];
}

void Gyro_MPU6050::readAll() {

    this->readMPU6050();
 
}//End readAll

void Gyro_MPU6050::calibrate(uint16_t calibrationSamples)
{
  
  float sumCalibratedRollValues = 0.0;
  float sumCalibratedPitchValues = 0.0;
  _count = 0;

  for(uint16_t countCalibrating=0;countCalibrating<calibrationSamples;countCalibrating++)
  {
        this->readAll();
        delay(2);
        sumCalibratedRollValues += this->roll();
        sumCalibratedPitchValues += this->pitch();
        _count +=1;
  }
  
  _startRollValue = sumCalibratedRollValues/calibrationSamples;
  _startPitchValue = sumCalibratedPitchValues/calibrationSamples;
}

float Gyro_MPU6050::getTemperature()
{
  
  return 0.0;
}
