
#include <HBRIDGE.h>

byte enable_leftChannel=10;
byte direction_leftChannel=11;
byte enable_rightChannel=12;
byte direction_rightChannel=13;

HBRIDGE rover = HBRIDGE(enable_leftChannel, direction_leftChannel, enable_rightChannel, direction_rightChannel);

void setup() {

  rover.debug();
  delay(1000);
  
}

void loop() {


}
