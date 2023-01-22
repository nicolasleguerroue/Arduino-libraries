#include "Arduino.h"
#include "LED.h"

LED::LED(byte led) 
{

	_led = led;	
	pinMode(_led, OUTPUT);
	
}


void LED::on() 
{
	digitalWrite(_led, 1);
}

void LED::on(unsigned long time) 
{
	digitalWrite(_led, 1);
	delay(time);
	digitalWrite(_led, 0);

}//End on



void LED::pwm(byte value) 
{
	analogWrite(_led, value);
}

void LED::pwm(byte value, unsigned long time) {

	analogWrite(_led, value);
	delay(time);
	analogWrite(_led, 0);
}//End pwm

void LED::blink(unsigned long timeHigh, unsigned long timeLow, unsigned long repeat) 
{
	for(int i=0;i<repeat;i++) {

		digitalWrite(_led, 1);
		delay(timeHigh);
		digitalWrite(_led, 0);
		delay(timeLow);

	}//End for

}//End blink

void LED::off()
{
	digitalWrite(_led, 0);
}