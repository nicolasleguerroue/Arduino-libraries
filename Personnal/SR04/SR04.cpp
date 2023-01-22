#include "Arduino.h"
#include "SR04.h"

SR04::SR04(int trig, int echo) 
{

  _trig = trig;
  _echo = echo;
  pinMode(_trig, OUTPUT);
  digitalWrite(_trig, LOW);
  pinMode(_echo, INPUT);

}//End 

float SR04::read(int unite) 
{

  digitalWrite(_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig, LOW);

  	_reading_echo = pulseIn(_echo, HIGH);
  	_cm = _reading_echo / 58;
    delay(2);
    if(unite==1) return _cm/100;
    if(unite==2) return _cm;


}


