/**
 * @file UART.cpp
 * @author Nicolas LE GUERROUE (nicolasleguerroue@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-11-29
 * 
 * @copyright 
 * 
 */
#include "Arduino.h"
#include "UART.h"
#include "SoftwareSerial.h"

UART::UART(int rx_device, int tx_device)  : _serial(tx_device, rx_device){}

void UART::begin(unsigned long bauds) 
{
	_serial.begin(bauds);
}
String UART::read() 
{
  String message="";
  
  if(_serial.available()>0) 
  {
  
    while(_serial.available()>0) 
    {
      c = _serial.read();
	    message += c;
	    delay(2);
	  }//End  while

    return message;
  }

}//End read


String UART::read(bool waitData) 
{

  String message="";
  uint16_t count = 0;

  if(waitData==WAIT_DATA) 
  {
    do 
    {
      delay(1);
      count += 1;
      if(count > _exitTime)
      {
        return "";
      } 
    }
    while(_serial.available()==0); 
 
    while(_serial.available()>0)
    {
	    c = _serial.read();
	    message = message + c;
	    delay(2);
	  }//End while

    return message;

  }//End do while

}//End read

void UART::send(String message) 
{

 	  _serial.println(message);

}//End send

void UART::send(int message) 
{
 	_serial.println(message);
}//End send

void UART::setExitTime(uint16_t exitTime)
{
  _exitTime = exitTime;
}//End setExitTime

