#include <SR04.h>

const int trig = 10;
const int echo = 11;

SR04 HC_SR(trig, echo);
float distance = 0;

void setup() {

  Serial.begin(9600);
  
}

void loop() {
  
  HC_SR.read(M);
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
  

}
