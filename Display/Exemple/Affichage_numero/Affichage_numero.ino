#include <Display.h>

byte b1=1;
byte b2=2;
byte b3=3;
byte b4=4;
byte b5=5;
byte b6=6;
byte b7=7;

Display afficheur(b1,b2,b3,b4,b5,b6,b7);


void setup() {

  afficheur.display(8); //affiche le nombre passé en arguments
  delay(1000);
  afficheur.off();//efface l'afficheur
  afficheur.blink(60,100,10,2);//fait clignoter l'afficheur

}

void loop() {

  afficheur.display(UN);
  delay(2000);
  afficheur.off();
  delay(2000);
  afficheur.blink(100,200,10,8);

}
