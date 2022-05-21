#include <UART.h>

const int RX = 10;//Rx de la carte Arduino
const int TX = 12;//Tx de la carte Arduino
String message;

UART module(RX,TX);

void setup() {

module.begin(HC_05); //initialise la communication série
Serial.begin(HC_05);

}

void loop() {

  message = module.read();

  if(message!="") {Serial.println(message);}
  
}
