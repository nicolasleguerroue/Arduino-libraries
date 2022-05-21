//Bibliothèque Display pour affichage 7 segments by Nicolas LE GUERROUE

#include "Arduino.h"
#include "Display.h"

Display::Display(byte b1, byte b2, byte b3, byte b4, byte b5, byte b6, byte b7) {


	_b1 = b1;
	_b2 = b2;
	_b3 = b3;
	_b4 = b4;
	_b5 = b5;
	_b6 = b6;
	_b7 = b7;

	pinMode(_b1, OUTPUT);
	pinMode(_b2, OUTPUT);
	pinMode(_b3, OUTPUT);
	pinMode(_b4, OUTPUT);
	pinMode(_b5, OUTPUT);
	pinMode(_b6, OUTPUT);
	pinMode(_b7, OUTPUT);

}


void Display::display(int nombre) {

switch(nombre) {

	case 0: clear();
			for(int i=0; i<6; i++) {digitalWrite(zero[i], HIGH);}
			break;

	case 1: clear();
			for(int i=0; i<2; i++) {digitalWrite(un[i], HIGH);}
			break;

	case 2: clear();
			for(int i=0; i<5; i++) {digitalWrite(deux[i], HIGH);}
			break;

	case 3: clear();
			for(int i=0; i<5; i++) {digitalWrite(trois[i], HIGH);}
			break;

 	case 4: clear();
			for(int i=0; i<4; i++) {digitalWrite(quatre[i], HIGH);} 
			break;

 	case 5: clear();
			for(int i=0; i<5; i++) {digitalWrite(cinq[i], HIGH);} 
			break;

 	case 6: clear();
			for(int i=0; i<6; i++) {digitalWrite(six[i], HIGH);}
			break;

 	case 7: clear();
			for(int i=0; i<3; i++) {digitalWrite(sept[i], HIGH);}
			break;

 	case 8:	clear();
			for(int i=0; i<7; i++) {digitalWrite(huit[i], HIGH);}
			break;


 	case 9: clear();
			for(int i=0; i<6; i++) {digitalWrite(neuf[i], HIGH);}
			break;
}//fin switch

}//fin display

void Display::blink(unsigned long delai_haut, unsigned long delai_bas, unsigned long nombre_de_fois, int valeur) {

clear();

switch(valeur) {

	case 0: for(int i=0; i<nombre_de_fois; i++) {

			display(0);
			delay(delai_haut);
			clear();
			delay(delai_bas);
			}//fin for
			break;

	case 1: for(int i=0; i<nombre_de_fois; i++) {

			display(1);
			delay(delai_haut);
			clear();
			delay(delai_bas);
			}//fin for
			break;

	case 2: for(int i=0; i<nombre_de_fois; i++) {

			display(2);
			delay(delai_haut);
			clear();
			delay(delai_bas);
			}//fin for
			break;

	case 3: for(int i=0; i<nombre_de_fois; i++) {

			display(3);
			delay(delai_haut);
			clear();
			delay(delai_bas);
			}//fin for
			break;

	case 4: for(int i=0; i<nombre_de_fois; i++) {

			display(4);
			delay(delai_haut);
			clear();
			delay(delai_bas);
			}//fin for
			break;

	case 5: for(int i=0; i<nombre_de_fois; i++) {

			display(5);
			delay(delai_haut);
			clear();
			delay(delai_bas);
			}//fin for
			break;

	case 6: for(int i=0; i<nombre_de_fois; i++) {

			display(6);
			delay(delai_haut);
			clear();
			delay(delai_bas);
			}//fin for
			break;

	case 7: for(int i=0; i<nombre_de_fois; i++) {

			display(7);
			delay(delai_haut);
			clear();
			delay(delai_bas);
			}//fin for
			break;

	case 8: for(int i=0; i<nombre_de_fois; i++) {

			display(8);
			delay(delai_haut);
			clear();
			delay(delai_bas);
			}//fin for
			break;

	case 9: for(int i=0; i<nombre_de_fois; i++) {

			display(9);
			delay(delai_haut);
			clear();
			delay(delai_bas);
			}//fin for
			break;

}//fin switch
}//fin blink

void Display::off() {

for(int i=0; i<7; i++) { digitalWrite(huit[i], LOW); }
		
}//fin clear



