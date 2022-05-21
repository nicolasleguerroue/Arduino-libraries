// Bibliothèque DISPLAY pour affichage 7 segments by Nicolas LE GUERROUE

#include "Arduino.h"

#define UN 1 
#define DEUX 2
#define TROIS 3
#define QUATRE 4
#define CINQ 5
#define SIX 6
#define SEPT 7
#define HUIT 8
#define NEUF 9
#define ZERO 0

class Display
{
public:
	
	Display(byte b1, byte b2, byte b3, byte b4, byte b5, byte b6, byte b7);
	void display(int nombre); //affiche le nombre passé en arguments
	void off();//efface l'afficheur
	void blink(unsigned long delai_haut, unsigned long delai_bas, unsigned long nombre_de_fois, int valeur);//fait clignoter l'afficheur

	byte _b1;
	byte _b2;
	byte _b3;
	byte _b4;
	byte _b5;
	byte _b6;
	byte _b7;

	const byte un [2] = {_b2, _b3};
	const byte deux [5] = {_b1, _b4, _b6, _b3, _b7};
	const byte trois [5] = {_b1, _b6, _b7, _b4, _b5};
	const byte quatre [4] = {_b2, _b4, _b6, _b5};
	const byte cinq [5] = {_b1, _b2, _b6, _b5, _b7};
	const byte six [6] = {_b1, _b2, _b6, _b6, _b3, _b7};
	const byte sept [3] = {_b1, _b4, _b5};
	const byte huit [7] = {_b1, _b2, _b3, _b4, _b5, _b6, _b7};
	const byte neuf [5] = {_b1, _b2, _b4, _b6, _b5};
	const byte zero [6] = {_b1, _b2, _b3, _b4, _b5, _b7};
	

};
