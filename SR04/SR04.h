/* Bibliothèque SR04 pour le module HC-SR04 by Nicolas LE GUERROUE
 * Version : 1.16.08.03
 */
#include "Arduino.h"
#define M 1
#define CM 2

class SR04
{
public:
	SR04(int trig, int echo);
	float read(int unite);//retourne la valeur en metre (read(M);) ou en cm (read(CM);)
	 
private: 
int _trig;
int _echo;
float _lecture_echo = 0;
float _cm = 0;
	
};