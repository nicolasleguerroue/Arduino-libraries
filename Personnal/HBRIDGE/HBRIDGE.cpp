#include "Arduino.h"
#include "HBRIDGE.h"

HBRIDGE::HBRIDGE(byte enable_leftChannel, byte direction_leftChannel, byte enable_rightChannel, byte direction_rightChannel)  
{
	
	_enable_leftChannel = enable_leftChannel;
	_direction_leftChannel = direction_leftChannel;
	_enable_rightChannel = enable_rightChannel;
	_direction_rightChannel = direction_rightChannel;
	
	pinMode(_enable_leftChannel, OUTPUT);
	pinMode(_enable_rightChannel, OUTPUT);
	pinMode(_direction_leftChannel, OUTPUT);
	pinMode(_direction_rightChannel, OUTPUT);
}


void HBRIDGE::debug() 
{

	pinMode(_enable_leftChannel, OUTPUT);
	pinMode(_enable_rightChannel, OUTPUT);
	pinMode(_direction_leftChannel, OUTPUT);
	pinMode(_direction_rightChannel, OUTPUT);

	
}

void HBRIDGE::on(
	byte direction_leftChannel, byte value_leftChannel, 
	byte direction_rightChannel, byte value_rightChannel) 
{

	analogWrite(_enable_leftChannel, value_leftChannel);
	analogWrite(_enable_rightChannel, value_rightChannel);
	digitalWrite(_direction_leftChannel, direction_leftChannel);
	digitalWrite(_direction_rightChannel, direction_rightChannel);


}

void HBRIDGE::on(
	byte direction_leftChannel, byte value_leftChannel, unsigned long time_leftChannel,     
	byte direction_rightChannel, byte value_rightChannel, unsigned long time_rightChannel ) 
{

	deltaTime = time_leftChannel - time_rightChannel;

	if(deltaTime>0) {

		analogWrite(_enable_leftChannel, value_leftChannel);
		analogWrite(_enable_rightChannel, value_rightChannel);
		digitalWrite(_direction_leftChannel, direction_leftChannel);
		digitalWrite(_direction_rightChannel, direction_rightChannel);
		delay(time_rightChannel);
		this->off(1,0);
		delay(deltaTime);
		this->off(0,0); 
	}
	
	if(deltaTime<0) { 

		analogWrite(_enable_leftChannel, value_leftChannel);
		analogWrite(_enable_rightChannel, value_rightChannel);
		digitalWrite(_direction_leftChannel, direction_leftChannel);
		digitalWrite(_direction_rightChannel, direction_rightChannel);
		delay(time_leftChannel);
		this->off(0,1);
		delay(abs(deltaTime));
		this->off(0,0); 

	}

	else {

		analogWrite(_enable_leftChannel, value_leftChannel);
		analogWrite(_enable_rightChannel, value_rightChannel);
		digitalWrite(_direction_leftChannel, direction_leftChannel);
		digitalWrite(_direction_rightChannel, direction_rightChannel);
		delay(time_leftChannel);
		this->off(0,0); 
	}

}

void HBRIDGE::off(bool state_leftChannel, bool state_rightChannel) {

	if(state_leftChannel==false) 
	{
		analogWrite(_enable_leftChannel, 0);
		digitalWrite(_direction_leftChannel, 0);
	}

	if(state_rightChannel==false) 
	{
		analogWrite(_enable_rightChannel, 0);
		digitalWrite(_direction_rightChannel, 0);	
	}
}//End off


