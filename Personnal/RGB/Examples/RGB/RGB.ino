//Available colros : RED-GREEN-BLUE-CYAN-ORANGE-WHITE-PURPLE-TURQUOISE-YELLOW-MAGENTA-ROSE
#include <RGB.h>

const int time_onState = 250;
const int time_lowState = 400;
const int nb_of_blink = 10;

RGB led_RGB(9,10,11); //R,G, B

void setup () {}

void loop () {

  led_RGB.on(GREEN);
  delay(1000);
  led_RGB.on(BLUE);
  delay(1000);
  led_RGB.blink(RED,time_onState, time_lowState, nb_of_blink); 
  led_RGB.randomRGB(10000,500);
  
}

