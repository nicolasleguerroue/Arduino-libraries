#include <Robot.h>
byte servo_d = 8;
byte servo_g = 9;
const int neutre_d = 1450;
const int neutre_g = 1450;
const byte BUZZER = 12;
const byte led_g = 2;
const byte led_d = 3;

Robot robot(servo_d, servo_g, neutre_d, neutre_g);

void setup() {
Serial.begin(9600);
}

void loop() {

  robot.avance(1000);
  robot.recule(1000);
  robot.droite(3000);
  robot.gauche(3000);
  robot.melodie1(BUZZER);
  robot.lumiere(led_g, led_d);
  delay(3000);
  robot.fin_lumiere(led_g, led_d);
  

}
