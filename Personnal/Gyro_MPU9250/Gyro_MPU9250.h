/**
 * @file Gyro_MPU9250.h	
 * @author Nicolas LE GUERROUE (nicolasleguerroue@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-11-29
 * 
 * @copyright
 * 
 */
#include "Arduino.h"
#include "quaternionFilters.h"
#include <EEPROM.h>
#include "MPU9250.h"


//EEEPROM
#define ADDRESS_ROLL 0x01
#define ADDRESS_PITCH 0x02
#define ADDRESS_YAW 0x03

#define SIGN_PITCH 0x04 
#define SIGN_ROLL 0x05
#define SIGN_YAW 0x06

#define SIGN_POSITIVE_VALUE 1  //If '1' in EEPROM, angle is negative
#define SIGN_ENGATIVE_VALUE 0

#define I2Cclock 400000
#define I2Cport Wire
#define ADDRESS_GYRO MPU9250_ADDRESS_AD0

#define ALGORITHM_MADWICK 0x00
#define ALGORITHM_MAHONY 0x01


//Calibration



/**
 * @brief Algorithm enum to select algo to compute data
 * 
 */
enum Algorithm 
{
	Madgwick = 0,
	Mahony = 1
};

/**
 * @brief Select speed unit for angles
 * 
 */
enum GyroSpeed
{
  radPerSec = 1,
  degPerSec = 0
};

class Gyro_MPU9250 		//Begin class MPU9250
{
public:

	/**
	 * @brief Construct a new Gyro_MPU9250 object
	 * 
	 * @param address : Address of MPU9250
	 */
   	Gyro_MPU9250(uint8_t address);  
	
	/**
	 * @brief Compute all data about device
	 * 
	 */
    void readAll();

	/**
	 * @brief Get the Accelerations object
	 * 
	 * @param ax 
	 * @param ay 
	 * @param az 
	 */
    void getAccelerations(float *ax, float *ay, float *az);

	/**
	 * @brief Get the Gyro Speeds object
	 * 
	 * @param gx 
	 * @param gy 
	 * @param gz 
	 * @param gyroSpeed 
	 */
    void getGyroSpeeds(float *gx, float *gy, float *gz, GyroSpeed gyroSpeed);
    
	/**
	 * @brief Set the Algorithm object
	 * 
	 * @param algo : Enum Algorithm type (Mahony or Madgwick)
	 */
	void setAlgorithm(Algorithm algo);

	/**
	 * @brief Set the Magnetic Declination object
	 * 
	 * @param magDeclination 
	 */
  	void setMagneticDeclination(float magDeclination);

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
	 * @brief Get absolute yaw value
	 * 
	 * @return float 
	 */
	inline float yaw()   { return _yaw;  }

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
	 * @brief get calibrated yaw value
	 * 
	 * @return float 
	 */
	inline float initYaw()   { return _startYawValue;  }

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
	 * @brief Get relative yaw value after calibrating
	 * 
	 * @return float 
	 */
	inline float relativeYaw()   { return (_startYawValue-_yaw);  }

    /**
     * @brief Calibrate sensor and save calibrated values (on each channel)
     * 
     * @param calibrationSamples : count of samples
     */
    void calibrate(uint16_t calibrationSamples);

	/**
	 * @brief Init the MPU sensor
	 * 
	 */
    void begin();

	/**
	 * @brief Get the Temperature of device
	 * 
	 * @return float 
	 */
    float getTemperature();

	/**
	 * @brief Store calibrated values in EEPROM to use it later
	 * 
	 */
	void storeValuesInEEPROM();


private:
	
  	Algorithm _algo = Algorithm::Mahony;
  	MPU9250 _mpu;
  
	float _roll = 0.0;
	float _pitch = 0.0;
  	float _yaw = 0.0;

  int _count = 0;

  //Calibration
  float _startRollValue = 0;
  float _startPitchValue = 0;
  float _startYawValue = 0;

  float _magneticDeclination = +15.49;
  

}; //End Gyro

