
#include <HBRIDGE.h>

byte enable_moteur_gauche=10;
byte sens_moteur_gauche=11;
byte enable_moteur_droite=12;
byte sens_moteur_droite=13;
HBRIDGE robot(enable_moteur_gauche, sens_moteur_gauche, enable_moteur_droite, sens_moteur_droite);

void setup() {

robot.debug();
delay(1000);
}

void loop() {

  robot.avance(255,1,1,5000);//avance pendant 5 s
  robot.recule(100,1,1,5000);//recule pendant 5 s
  robot.droite(255,1,1,5000);//tourne à droite pendant 5 s
  robot.gauche(255,1,1,5000);//tourne à gauche pendant 5 s 
}
