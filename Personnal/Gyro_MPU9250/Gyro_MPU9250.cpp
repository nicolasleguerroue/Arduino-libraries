/**
 * @file Gyro_MPU9250.cpp 
 * @author Nicolas LE GUERROUE (nicolasleguerroue@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-11-29
 * 
 * @copyright 
 * 
 */
#include "Gyro_MPU9250.h"

Gyro_MPU9250::Gyro_MPU9250(uint8_t address)
{
	_mpu = MPU9250(address, I2Cport, I2Cclock);
}

void Gyro_MPU9250::begin() {

  Wire.begin();  //I2C start
  
  _mpu.calibrateMPU9250(_mpu.gyroBias, _mpu.accelBias);
  _mpu.initMPU9250();

  // Get magnetometer calibration 
  _mpu.initAK8963(_mpu.factoryMagCalibration);

  _mpu.getAres();
  _mpu.getGres();
  _mpu.getMres();
	
}//End begin

void Gyro_MPU9250::getAccelerations(float *ax, float *ay, float *az)
{
  _mpu.readAccelData(_mpu.accelCount);  // Read the x/y/z values

  //Convert accel to g
  *ax = (float)_mpu.accelCount[0] * _mpu.aRes - _mpu.accelBias[0];
  *ay = (float)_mpu.accelCount[1] * _mpu.aRes - _mpu.accelBias[1];
  *az = (float)_mpu.accelCount[2] * _mpu.aRes - _mpu.accelBias[2];
  
}

void Gyro_MPU9250::setMagneticDeclination(float magDeclination)
{
  _magneticDeclination = magDeclination;
}

void Gyro_MPU9250::getGyroSpeeds(float *gx, float *gy, float *gz, GyroSpeed gyroSpeed)
{
    _mpu.readGyroData(_mpu.gyroCount);  // Read the x/y/z values

    // Convert into degrees per second or rad per sec according the gyroSpeed value
    *gx = (gyroSpeed == GyroSpeed::degPerSec) ? DEG_TO_RAD*(float)_mpu.gyroCount[0] * _mpu.gRes : (float)_mpu.gyroCount[0] * _mpu.gRes;
    *gy = (gyroSpeed == GyroSpeed::degPerSec) ? DEG_TO_RAD*(float)_mpu.gyroCount[1] * _mpu.gRes : (float)_mpu.gyroCount[1] * _mpu.gRes;
    *gz = (gyroSpeed == GyroSpeed::degPerSec) ? DEG_TO_RAD*(float)_mpu.gyroCount[2] * _mpu.gRes : (float)_mpu.gyroCount[1] * _mpu.gRes;
  
}

void Gyro_MPU9250::readAll() {

    _mpu.readAccelData(_mpu.accelCount);  // Read the x/y/z values

    //Convert accel to g
    _mpu.ax = (float)_mpu.accelCount[0] * _mpu.aRes; // - _mpu.accelBias[0];
    _mpu.ay = (float)_mpu.accelCount[1] * _mpu.aRes; // - _mpu.accelBias[1];
    _mpu.az = (float)_mpu.accelCount[2] * _mpu.aRes; // - _mpu.accelBias[2];

    _mpu.readGyroData(_mpu.gyroCount);  // Read the x/y/z values

    // Convert into degrees per second
    _mpu.gx = (float)_mpu.gyroCount[0] * _mpu.gRes;
    _mpu.gy = (float)_mpu.gyroCount[1] * _mpu.gRes;
    _mpu.gz = (float)_mpu.gyroCount[2] * _mpu.gRes;


    _mpu.readMagData(_mpu.magCount);  // Read the x/y/z values

    // Convert in milliGauss with corrections
    _mpu.mx = (float)_mpu.magCount[0] * _mpu.mRes
               * _mpu.factoryMagCalibration[0] - _mpu.magBias[0];
    _mpu.my = (float)_mpu.magCount[1] * _mpu.mRes
               * _mpu.factoryMagCalibration[1] - _mpu.magBias[1];
    _mpu.mz = (float)_mpu.magCount[2] * _mpu.mRes
               * _mpu.factoryMagCalibration[2] - _mpu.magBias[2];

  //Update time for quaternion update
  _mpu.updateTime();

  if(_algo == Algorithm::Mahony)
  {
    MahonyQuaternionUpdate(_mpu.ax, _mpu.ay, _mpu.az, _mpu.gx * DEG_TO_RAD,
                         _mpu.gy * DEG_TO_RAD, _mpu.gz * DEG_TO_RAD, _mpu.my,
                         _mpu.mx, _mpu.mz, _mpu.deltat);
  }
  else if(_algo == Algorithm::Madgwick)
  {
    MadgwickQuaternionUpdate(_mpu.ax, _mpu.ay, _mpu.az, _mpu.gx * DEG_TO_RAD,
                         _mpu.gy * DEG_TO_RAD, _mpu.gz * DEG_TO_RAD, _mpu.my,
                         _mpu.mx, _mpu.mz, _mpu.deltat);
  }
  else {
    return;
  }


  _mpu.yaw   = atan2(2.0f * (*(getQ()+1) **(getQ()+2) + *getQ()**(getQ()+3)), *getQ() * *getQ() + *(getQ()+1)**(getQ()+1) - *(getQ()+2) * *(getQ()+2) - *(getQ()+3)**(getQ()+3));
  _mpu.pitch = -asin(2.0f * (*(getQ()+1) **(getQ()+3) - *getQ()**(getQ()+2)));
  _mpu.roll  = atan2(2.0f * (*getQ() * *(getQ()+1) + *(getQ()+2)
                    * *(getQ()+3)), *getQ() * *getQ() - *(getQ()+1)
                    * *(getQ()+1) - *(getQ()+2) * *(getQ()+2) + *(getQ()+3)
                    * *(getQ()+3));

  _mpu.pitch *= RAD_TO_DEG;
  _mpu.yaw   *= RAD_TO_DEG;
  
  _mpu.yaw  += _magneticDeclination;  //Offset of declination
  _mpu.roll *= RAD_TO_DEG;

  _mpu.count = millis();
  _mpu.sumCount = 0;
  _mpu.sum = 0;

  _roll = _mpu.roll;
  _pitch = _mpu.pitch;
  _yaw = _mpu.yaw;  

}//End read

void Gyro_MPU9250::setAlgorithm(Algorithm algo)
{
  _algo = algo;
}

void Gyro_MPU9250::storeValuesInEEPROM()
{
  EEPROM.update(ADDRESS_ROLL, (uint8_t)abs(this->initRoll()));
  EEPROM.update(ADDRESS_PITCH, (uint8_t)abs(this->initPitch()));
  EEPROM.update(ADDRESS_YAW, (uint8_t)abs(this->initYaw()));
}


void Gyro_MPU9250::calibrate(uint16_t calibrationSamples)
{
  
  float sumCalibratedRollValues = 0.0;
  float sumCalibratedPitchValues = 0.0;
  float sumCalibratedYawValues = 0.0;
  _count = 0;
  
  for(int16_t integerAccuracy=0;integerAccuracy<2000;integerAccuracy++) 
  {
    this->readAll();
  }  //Increase accuracy of integer value

  for(uint16_t countCalibrating=0;countCalibrating<calibrationSamples;countCalibrating++)
  {
        this->readAll();
        delay(1);
        sumCalibratedRollValues += this->roll();
        sumCalibratedPitchValues += this->pitch();
        sumCalibratedYawValues += this->yaw();
        _count +=1;
  }
  
  _startRollValue = sumCalibratedRollValues/calibrationSamples;
  _startPitchValue = sumCalibratedPitchValues/calibrationSamples;
  _startYawValue = sumCalibratedYawValues/calibrationSamples;

}

float Gyro_MPU9250::getTemperature()
{
  _mpu.tempCount = _mpu.readTempData();   // Read the ADC values
  _mpu.temperature = ((float) _mpu.tempCount) / 333.87 + 21.0;
  return _mpu.temperature;
}
