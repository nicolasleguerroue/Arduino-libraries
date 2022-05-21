//Couleurs disponibles : RED-GREEN-BLUE-CYAN-ORANGE-WHITE-PURPLE-TURQUOISE-YELLOW-MAGENTA-ROSE
#include <RGB.h>

const int duree_etat_haut = 250;
const int duree_etat_bas = 400;
const int nb_of_blink = 10;

RGB led_RGB(9,10,11);//Broches R, G et B

void setup () {}

void loop () {

  led_RGB.on(GREEN);
  delay(1000);
  led_RGB.on(BLUE);
  delay(1000);
  led_RGB.blink(RED,duree_etat_haut, duree_etat_bas, nb_of_blink); 
  led_RGB.randomRGB(10000,500);
  
}

