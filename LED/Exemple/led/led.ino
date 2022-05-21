#include <LED.h>

LED led(13);

void setup() {
	
led.on();
delay(1000);

}

void loop() {

  led.off();
  delay(1000);
  led.on(3000);
  led.blink(60,100,10);
  led.pwm(100,300);


}
