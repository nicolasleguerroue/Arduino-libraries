#ifndef JOYSTICK_H
#define JOYSTICK_H

#define LOCKED_JOYSTICK 0xff  		//Attente de l'appui d'un bouton si constante appelée

#define UP 0xf0 		//Valeur de retour pour joystick vers le haut
#define DOWN 0xf1 		//Valeur de retour pour joystick vers le bas
#define RIGHT 0xf2 		//Valeur de retour pour joystick vers la droite
#define LEFT 0xf3 		//Valeur de retour pour joystick vers la gauche
#define CENTER 0xf4 	//Valeur de retour pour le bouton enfoncé
#define SHORT_PUSH 0xf5
#define LONG_PUSH 0xf6
#define VOID 0xf7

#define OFFSET 50 		//décalage de la valeur moyenne au repos
#define MAX 900 		//Valeur max pour une butée
#define MIN 150 		//Valeur min pour une butée
#define BOUND 10   	//Anti-rebond

#define SHORT_DELAY 200 	//Délai court
#define LONG_DELAY 2000		//délai long



class Joystick
{
public:


	Joystick( int axe_x, int axe_y, int button, int type); 	//type est INPUT_PULLUP ou rien
	void setShortTime(int short_delay); 						//
	void setLongTime(int long_delay);
	int read(); 											//Lecture instantannée
  void begin();


private:

	int _button=0;
	int _axe_x=0;
	int _axe_y=0;
	int _mode=0;

	int _short_delay = 100;
	int _long_delay = 400;

	
};


#endif
