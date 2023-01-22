/**
 * @file Gyro_MPU6050.h	
 * @author Nicolas LE GUERROUE (nicolasleguerroue@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-11-29
 * 
 * @copyright
 * 
 */
#include "Arduino.h"
#include<Wire.h>
#include <math.h>
#define NumData 7
#define pi      3.1415926535897932384626433832795  
#define MPU6050_ADDRESS     0x68

/**
 * @brief Select speed unit for angles
 * 
 */
enum GyroSpeed
{
  radPerSec = 1,
  degPerSec = 0
};

class Gyro_MPU6050 		//Begin class Gyro_MPU6050
{
public:

	/**
	 * @brief Construct a new MPU6050 object
	 * 
	 * @param address : Address of MPU6050
	 */
   	Gyro_MPU6050(uint8_t address);  
	
	/**
	 * @brief Compute all data about device
	 * 
	 */
    void readAll();

	/**
	 * @brief Read data
	 * 
	 */
    void readMPU6050();

	/**
	 * @brief Compute angles
	 * 
	 */
    void computeAngle();

	
	/**
	 * @brief Get the Accelerations object : NOT IMPLEMENTED
	 * 
	 * @param ax 
	 * @param ay 
	 * @param az 
	 */
    void getAccelerations(float *ax, float *ay, float *az);

	/**
	 * @brief Get the Gyro Speeds object : NOT IMPLEMENTED
	 * 
	 * @param gx 
	 * @param gy 
	 * @param gz 
	 * @param gyroSpeed 
	 */
    void getGyroSpeeds(float *gx, float *gy, float *gz, GyroSpeed gyroSpeed);
    
	/**
	 * @brief get absolute roll value
	 * 
	 * @return float 
	 */
	inline float roll()  { return _roll; }

	/**
	 * @brief get absolute pitch value
	 * 
	 * @return float 
	 */
	inline float pitch() { return _pitch;}


	/**
	 * @brief Get calibrated roll value
	 * 
	 * @return float 
	 */
	inline float initRoll()  { return _startRollValue; }

	/**
	 * @brief Get calibrated pitch value
	 * 
	 * @return float 
	 */
	inline float initPitch() { return _startPitchValue;}


	/**
	 * @brief get relative roll value after calibrating sensor
	 * 
	 * @return float 
	 */
	inline float relativeRoll()  { return (_startRollValue-_roll); }

	/**
	 * @brief Get relative pitch value after calibrating sensor
	 * 
	 * @return float 
	 */
	inline float relativePitch() { return (_startPitchValue-_pitch);}

   	/**
	 * @brief Init the MPU sensor
	 * 
	 */
    void begin();

	/**
	 * @brief Calibrate the sensor
	 * 
	 * @param calibrationSamples 
	 */
    void calibrate(uint16_t calibrationSamples);

	/**
	 * @brief Get the Temperature of device : NOT IMPLEMENTED
	 * 
	 * @return float 
	 */
    float getTemperature();



private:
	
    //MPU6050
    int  GyAccTemp[7];
    int  GATCorr[7]={0,0,0,0,0,0,0};
    double PitchRoll[3];

    int _address = 0x68;
  
	float _roll = 0.0;
	float _pitch = 0.0;
  	float _yaw = 0.0;

  int _count = 0;

  //Calibration
  float _startRollValue = 0;
  float _startPitchValue = 0;
  float _startYawValue = 0;
  

}; //End Gyro__MPU6050

