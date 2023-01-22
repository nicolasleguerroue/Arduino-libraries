/**
 * @file HBRIDGE.h
 * @author Nicolas LE GUERROUE
 * @brief 
 * @version 1.0
 * @date 2023-01-22
 * 
 */
#include "Arduino.h"

#define MAX 255
#define MIN 0
#define MED 127

/**
 * @brief HBRIDGE class
 * 
 */
class HBRIDGE 		
{
public:

   /**
    * @brief Construct a new HBRIDGE object
    * 
    * @param enable_leftChannel : Enable pin on left Channel
    * @param direction_leftChannel  : Direction pin on left Channel
    * @param enable_rightChannel : Enable pin on right Channel
    * @param direction_rightChannel : Direction pin on right Channel
    */
   HBRIDGE(byte enable_leftChannel, byte direction_leftChannel, byte enable_rightChannel, byte direction_rightChannel);
   
   /**
    * @brief Debug HBRIDGE
    * 
    */
   void debug();

   /**
    * @brief Start motor
    * 
    * @param direction_leftChannel 
    * @param value_leftChannel 
    * @param direction_rightChannel 
    * @param value_rightChannel 
    */
   void on(
      byte direction_leftChannel, 
      byte value_leftChannel, 
      byte direction_rightChannel, 
      byte value_rightChannel);

   /**
    * @brief Start motor
    * 
    * @param direction_leftChannel 
    * @param value_leftChannel 
    * @param time_leftChannel 
    * @param direction_rightChannel 
    * @param value_rightChannel 
    * @param delai_motor_droite_on 
    */
   void on(
      byte direction_leftChannel, 
      byte value_leftChannel, 
      unsigned long time_leftChannel,     
      byte direction_rightChannel, 
      byte value_rightChannel, 
      unsigned long delai_motor_droite_on);

   /**
    * @brief Stop motor
    * 
    * @param state_leftChannel 
    * @param state_rightChannel 
    */
   void off(bool state_leftChannel, bool state_rightChannel);


private:

	byte _enable_leftChannel; 
	byte _direction_leftChannel;
	byte _enable_rightChannel; 
	byte _direction_rightChannel;

   byte value_leftChannel = 100; //default value
   byte value_rightChannel = 100;

   int stepTime;
   unsigned long deltaTime;

};



