// Bibliothèque Magneto pour capteur capacitif
// AUTEUR : Nicolas LE GUERROUE
#include "Arduino.h"
#include "CapPin.h"

class Magneto
{
public:
	Magneto(uint8_t pin);
	bool read(void);//affiche true ou false en fonction du contact
	bool read(int delai_if_true);//affiche true ou false en fonction du contact
	
private:

 	CapPin CapSense;
	
};//FIN CLASSE MAGNETO