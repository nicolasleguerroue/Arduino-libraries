#include "Arduino.h"
#include "RS232.h"

RS232::RS232()  {
}

void RS232::begin(unsigned long bauds) 
{
	Serial.begin(bauds);
}
String RS232::read() 
{
  String message="";
  
  if(Serial.available()>0) 
  {
  
    while(Serial.available()>0) 
    {
      c = Serial.read();
	    message += c;
	    delay(2);
	  }//End  while

    return message;
  }

}//End read


String RS232::read(bool waitData) 
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
    while(Serial.available()==0); 
 
    while(Serial.available()>0)
    {
	    c = Serial.read();
	    message = message + c;
	    delay(2);
	  }//End while

    return message;

  }//End do while

}//End read

void RS232::send(String message) 
{

 	  Serial.println(message);

}//End send

void RS232::send(int message) 
{
 	Serial.println(message);
}//fin send

void RS232::setExitTime(uint16_t exitTime)
{
  _exitTime = exitTime;
}

