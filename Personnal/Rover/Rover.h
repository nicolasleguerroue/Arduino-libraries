/**
 * @file Rover.h
 * @author Nicolas LE GUERROUE (nicolasleguerroue@gmail.com) 
 * @brief 
 * @version 1.0
 * @date 2022-11-29
 * 
 * @copyright 
 * 
 */

#ifndef ROVER_H
#define ROVER_H

#include "Arduino.h"
#include "SoftwareSerial.h"


#define VALUE_STOP 180
#define VALUE_MIN_SPEED_FORWARD 195
#define VALUE_MAX_SPEED_FORWARD 240
#define VALUE_MIN_SPEED_BACKWARD 150
#define VALUE_MAX_SPEED_BACKWARD 100
#define VALUE_SPEED_LEFT 175
#define VALUE_SPEED_RIGHT 195
#define VALUE_SPEED_TURN_FORWARD 220


enum roverPosition
{
    STOP = 0,
    LEFT =  1,
    RIGHT = 2,
    FORWARD = 3,
    BACKWARD = 4
  };

  
class Rover 		
{

public:

  /**
   * @brief Construct a new Rover object
   * 
   * @param pinRight : Right pin control
   * @param pinLeft : Left pin control
   */
  Rover(uint8_t pinRight, uint8_t pinLeft); 

  /**
   * @brief Set the Debug object
   * 
   * @param debug : If true, enable debug
   */
  void setDebug(bool debug);

  /**
   * @brief Add Debug Channel
   * 
   * @param serial : Serial object (reference)
   * @param baudrate : Baudrate of debug channel
   */
  void addDebugChannel(HardwareSerial *serial, uint16_t baudrate);

  /**
   * @brief Start forwarding bot
   * 
   */
  void forward();

  /**
   * @brief Start backwarding bot
   * 
   */
  void backward();

  /**
   * @brief Turn the bot on right
   * 
   */
  void right();

  /**
   * @brief Turn the bot on left
   * 
   */
  void left();

  /**
   * @brief Stop the bot
   * 
   */
  void stop();

  /**
   * @brief Turn on left and forward the bot
   * 
   */
  void left_forward();

  /**
   * @brief Turn on right and forward the bot
   * 
   */
  void right_forward();


private:

  uint8_t _pinRight = 3;
  uint8_t _pinLeft = 9;
  int _lastPosition = 0;

  bool _debug = false;
  HardwareSerial *_serial;

    

}; //End Rover

#endif
