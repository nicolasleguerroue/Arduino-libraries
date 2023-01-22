#include <UART.h>

const int RX_DEVICE = 10;
const int TX_DEVICE = 12;

String message;

UART device = UART(RX_DEVICE,TX_DEVICE);

void setup() {

  device.begin(HC_05); 
  Serial.begin(HC_05);

}

void loop() {

  message = device.read();

  if(message!="") {Serial.println(message);}
  
}
