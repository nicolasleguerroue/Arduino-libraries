/* Bibliothèque SR04 pour le module HC-SR04 by Nicolas LE GUERROUE
 * Version : 1.16.08.03
 */
#include "Arduino.h"
#include "SR04.h"

SR04::SR04(int trig, int echo) {

_trig = trig;
_echo = echo;
pinMode(_trig, OUTPUT);
digitalWrite(_trig, LOW);
pinMode(_echo, INPUT);

}//fin constructeur

float SR04::read(int unite) {

digitalWrite(_trig, HIGH);//creation d'une impulsion de 10 µs
delayMicroseconds(10);
digitalWrite(_trig, LOW);

  	_lecture_echo = pulseIn(_echo, HIGH);
  	_cm = _lecture_echo / 58;
    delay(2);
    if(unite==1) return _cm/100;
    if(unite==2) return _cm;


}


