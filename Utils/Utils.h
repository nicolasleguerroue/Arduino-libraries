// Bibliothèque Utils pour utiliser des focntions spécifiques
// AUTEUR : Nicolas LE GUERROUE
#include "Arduino.h"

#define PULL_UP 1
#define INPUT_PULL_UP 2
#define PULL_DOWN 3

class Utils {

public:

  Utils(); // constructeur
  float batterie(byte PONT_DIVISEUR, float coefficient);//lire un pont diviseur de tension
  int analog(byte ENTREE, int nb_read); //lit la valeur d'une entrée analogique
  float temperature_from_LM35(byte pin_LM35);//lit la temperature donnée par un LM35
  bool buttonIsPushed(int button_pin, int config_button);//lit un bouton 
  bool buttonIsPushed(int button_pin, int config_button, int locked);//attend qu'un bouton soit pressé 

 private:

 	bool state_button = false;
 	int valeur;
    unsigned long somme;
 	//config_button = PULL_DOWN or PULL_UP or INPUT_PULL_UP
 	//					(0x3)		(0x1)		(0x2)
};//FINC CLASSE UTILS
