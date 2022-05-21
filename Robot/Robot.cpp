/* Bibliothèque Robot  pour servomoteurs by Nicolas LE GUERROUE
 * Version : 1.16.08.03
 */
#include "Arduino.h"
#include "Servo.h"
#include "Robot.h"


Robot::Robot(int pin_droite,int pin_gauche, int neutre_droite, int neutre_gauche) {
    
	
_neutre_gauche = neutre_gauche;
_pin_gauche = pin_gauche;
_neutre_droite = neutre_droite;
_pin_droite = pin_droite;

ServoGauche.attach(_pin_gauche);
ServoDroite.attach(_pin_droite);
ServoGauche.writeMicroseconds(_neutre_gauche);
ServoDroite.writeMicroseconds(_neutre_droite);

	
}//fin constructeur



void Robot::avance() {

	ServoGauche.writeMicroseconds(2000);
	ServoDroite.writeMicroseconds(1000);
}

void Robot::avance(unsigned long delai) {

	avance();
	delay(delai);
	arret();
}

void Robot::recule() {
	
	ServoGauche.writeMicroseconds(1000);
	ServoDroite.writeMicroseconds(2000);
}

void Robot::recule(unsigned long delai) {
	
	recule();
    delay(delai);
	arret();
}

void Robot::droite() {

	ServoGauche.writeMicroseconds(1000);
	ServoDroite.writeMicroseconds(1000);
}	

void Robot::droite(unsigned long delai) {

	droite();
	delay(delai);
	arret();
}			   

void Robot::gauche() {

	ServoGauche.writeMicroseconds(2000);
	ServoDroite.writeMicroseconds(2000);
}

void Robot::gauche(unsigned long delai) {

	gauche();
	delay(delai);
	arret();
}

void Robot::arret() {
	
	ServoGauche.writeMicroseconds(_neutre_gauche);
	ServoDroite.writeMicroseconds(_neutre_gauche);
}


void Robot::melodie1(const int BUZZER) {


const int nombreNotes=11; 
int note[nombreNotes]= {SOL,SOL,SOL,LA,SI,LA,SOL,SI,LA,LA,SOL}; 
float duree[nombreNotes]={1 ,1 ,1 ,1 ,2 ,2 ,1 ,1 ,1 ,1 ,1}; 

	for(int i=0; i<nombreNotes; i++) {				//JOUE UNE MÉLODIE
                    tone(BUZZER, note[i]); 
                    delay(350*duree[i]); 
                    noTone(BUZZER); 
                    delay(20);}
}


void Robot::melodie2(const int BUZZER) {


const int nombreNotes=14; 
int note[nombreNotes]= {MI,LA,DO,SI,LA,MIH,RE,SI,LA,DO,SI,SOL,SIB,MI}; 
float duree[nombreNotes]={1,2,0.5,1,2,1,3,3,1.5,0.5,1,2,1,4}; 

	for(int i=0; i<nombreNotes; i++) {				//JOUE UNE MÉLODIE
                    tone(BUZZER, note[i]); 
                    delay(350*duree[i]); 
                    noTone(BUZZER); 
                    delay(20);}
}


void Robot::lumiere(int led_g, int led_d) {

	pinMode(led_g, OUTPUT);
	pinMode(led_d, OUTPUT);
	digitalWrite(led_g, HIGH);
	digitalWrite(led_d, HIGH);

}

void Robot::fin_lumiere(int led_g, int led_d) {

	digitalWrite(led_g, LOW);
	digitalWrite(led_d, LOW);

}


