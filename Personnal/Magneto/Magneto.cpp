#include "Arduino.h"
#include "Magneto.h"
#include "CapPin.h"

Magneto::Magneto(uint8_t pin) 
: CapSense(pin)
{}

void Magneto::debug(void) {

	bool reading = false;

	do {
		reading = this->read();
	}
	while(reading==false);

	digitalWrite(13,1);
	delay(2000);
	digitalWrite(13,0);


}//End debug

bool Magneto::read(void) {

	long value =  CapSense.readPin(2000);
	if(value>0) {
		return true;
	}
	else {
		return false;
	}
}
