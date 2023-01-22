#include <RS232.h>

String message;

RS232 computer;

void setup() {

  computer.begin(9600);

}

void loop() {

  message = computer.read(WAIT_DATA);

  if(message!="") {computer.send(message);}

}
