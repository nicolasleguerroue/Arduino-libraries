#include <RS232.h>

String message;

RS232 computer;

void setup() {

  computer.begin(9600);

}

void loop() {

  message = computer.read(LOCKED);

  if(message!="") {computer.send(message);}

}
