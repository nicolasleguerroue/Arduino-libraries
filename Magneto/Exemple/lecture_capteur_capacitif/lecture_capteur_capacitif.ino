#include <Magneto.h>

Magneto bobine(8);//broche de la bobine

void setup() {
	
  Serial.begin(9600);
}

void loop() {

  if(bobine.read()) Serial.println("Appui detecte");


}
