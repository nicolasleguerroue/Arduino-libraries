//BIBLIOTHEQUE RS232
#include "Arduino.h"
#include "RS232.h"

RS232::RS232()  {

 
  
}

void RS232::begin(unsigned long bauds) {//private

  Serial.begin(bauds);
}

String RS232::read(void) {

  

message="";

  while(Serial.available()>0) {

    c = Serial.read();
    delay(2);
    message = message + c;
  }//fin while
  return message;
}//fin lecture

String RS232::read(uint8_t position) {

message="";

if(position==LOCKED) {

  do 	{
		delayMicroseconds(1);
		}
  while(Serial.available()==0);

  while(Serial.available()>0) {

    c = Serial.read();
    delay(2);
    message = message + c;
    
  }
  return message;
}
}//fin lecture

void RS232::send(String message)  { Serial.println(message);}

void RS232::send(int message)     { Serial.println(message);}
                                  


//FIN BIBLIOTHEQUE RS232