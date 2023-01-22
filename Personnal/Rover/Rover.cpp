/**
 * @file Rover.cpp
 * @author Nicolas LE GUERROUE (nicolasleguerroue@gmail.com) 
 * @brief 
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright
 * 
 */
#include "Rover.h"

Rover::Rover(uint8_t pinRight, uint8_t pinLeft)
{
    _pinRight = pinRight;
    _pinLeft = pinLeft;
    
    pinMode(pinRight, OUTPUT);
    pinMode(pinLeft, OUTPUT);
}

void Rover::setDebug(bool debug)
{
  _debug = debug;
}

void Rover::addDebugChannel(HardwareSerial *serial, uint16_t baudrate)
{
  _serial = serial;
  _serial->begin(baudrate);
}

void Rover::forward() 
{
  if(this->_debug) 
  {  
    _serial->println("Forward");
  }
  analogWrite(_pinRight, VALUE_MAX_SPEED_FORWARD); 
  analogWrite(_pinLeft, VALUE_MAX_SPEED_FORWARD);
  //_lastPosition = roverPosition::FORWARD;
}

void Rover::backward() 
{
  if(this->_debug) 
  {  
    _serial->println("backward");
  }
  analogWrite(_pinRight, VALUE_MIN_SPEED_BACKWARD); 
  analogWrite(_pinLeft, VALUE_MIN_SPEED_BACKWARD);
  //_lastPosition = roverPosition::BACKWARD;
}

void Rover::right() 
{
  if(this->_debug) 
  {  
    _serial->println("Right");
  }
  analogWrite(_pinRight, VALUE_MIN_SPEED_BACKWARD); 
  analogWrite(_pinLeft, VALUE_MIN_SPEED_FORWARD);
  //_lastPosition = roverPosition::RIGHT;
}

void Rover::left() 
{
  if(this->_debug) 
  {  
    _serial->println("Left");
  }
  analogWrite(_pinLeft, VALUE_MIN_SPEED_BACKWARD);
  analogWrite(_pinRight, VALUE_MIN_SPEED_FORWARD);
  //_lastPosition = roverPosition::LEFT;
}

void Rover::left_forward() 
{
  if(this->_debug) 
  {  
    _serial->println("Left and forward");
  }
  analogWrite(_pinLeft, VALUE_MIN_SPEED_BACKWARD);
  analogWrite(_pinRight, VALUE_SPEED_TURN_FORWARD);
  //_lastPosition = roverPosition::LEFT;
}

void Rover::right_forward() 
{
  if(this->_debug) 
  {  
    _serial->println("Left and forward");
  }
  analogWrite(_pinRight, VALUE_MIN_SPEED_BACKWARD);
  analogWrite(_pinLeft, VALUE_SPEED_TURN_FORWARD);
  //_lastPosition = roverPosition::LEFT;
}

void Rover::stop()
{
  if(this->_debug) 
  {  
    _serial->println("Stop");
  }
  analogWrite(_pinRight, VALUE_STOP); 
  analogWrite(_pinLeft, VALUE_STOP);
  //_lastPosition = roverPosition::STOP;
}
