//BIBLIOTHEQUE MAGNETO
#include "Arduino.h"
#include "Magneto.h"
#include "CapPin.h"

Magneto::Magneto(uint8_t pin) 
: CapSense(pin)
{}

void Magneto::debug(void) {

bool lecture = false;

do {lecture = read();}

while(lecture==false);

digitalWrite(13,1);
delay(2000);
digitalWrite(13,0);


}//fin debug

bool Magneto::read(void) {

	long valeur =  CapSense.readPin(2000);
	if(valeur>0) {return true;}

	if(valeur==0) {return false;}	
}

bool Magneto::read(int delai_if_true) {

	long valeur =  CapSense.readPin(2000);
	if(valeur>0) { 	delay(delai_if_true);
					return true;}

	if(valeur==0) {return false;}	
}


//FIN BIBLIOTHEQUE MAGNETO
