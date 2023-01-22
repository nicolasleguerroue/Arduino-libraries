#include <Magneto.h>

Magneto sensor(8);  //capacitive sensor pin

void setup() {
	
  Serial.begin(9600);
}

void loop() {

  if(sensor.read()) {
    Serial.println("Something detected by sensor");
    delay(100);
  }


}
