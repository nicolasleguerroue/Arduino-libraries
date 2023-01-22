#include <LED.h>

LED led(INTERNAL_LED); 

void setup() {
	
}

void loop() {

  //Power-on
  led.on();
  delay(1000);
  led.off();

  //Power-on for 3 s
  led.on(3000);

  //Blink
  led.blink(60,100,20);

  //PWM
  led.pwm(100,1000);
  led.pwm(200,1000);
  led.pwm(255,1000);

}
