/* Bibliothèque Robot  pour servomoteurs by Nicolas LE GUERROUE
 * Version : 1.16.08.03
 */
#include "Arduino.h"
#include "Servo.h"


#define DO 262
#define RE 294
 #define MI 330
 #define FA 349
 #define SOL 392
 #define LA 440
 #define SI 494
 #define MIH 350
 #define SIB 455

class Robot {

public:
Robot(int pin_droite,int pin_gauche, int neutre_droite, int neutre_gauche);		//constructeur
void avance();//fait avancer le robot
void avance(unsigned long delai);//fait avancer le robot pendant x ms
void recule();//fait reculer le robot
void recule(unsigned long delai);
void gauche();//fait tourner à gauche le robot
void gauche(unsigned long delai);
void droite();//fait tourner à droite le robot
void droite(unsigned long delai);
void arret();//fait arreter le robot
void melodie1(const int BUZZER);//joue une mélodie
void melodie2(const int BUZZER);//joue une autre mélodie
void lumiere(int led_g, int led_d);//allume les leds du robot
void fin_lumiere(int led_g, int led_d);//eteint les leds

Servo ServoGauche;	//création d'un objet ServoGauche pour le servo de gauche
Servo ServoDroite;	//création d'un objet ServoDroite pour le servo de droite

private:
int _neutre_gauche; 	//valeur neutre du servo de gauche
int _neutre_droite; 	//valeur neutre du servo de droite

int _pin_gauche;	//broche du servo de gauche
int _pin_droite;		//broche du servo de droite

};
