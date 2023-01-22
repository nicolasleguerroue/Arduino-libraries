/**
 * @file LED.h
 * @author Nicolas Le Guerroué (nicolasleguerroue@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2023-01-22
 * 
 */

#ifndef LED_H
#define LED_H

#include "Arduino.h"

#define INTERNAL_LED 13

/**
 * @brief LED class
 * 
 */
class LED
{
public:
	
	/**
	 * @brief Construct a new LED object
	 * 
	 * @param led : pin of LED
	 */
	LED(byte led);

	/**
	 * @brief Power on the LED
	 * 
	 */
	void on();

	/**
	 * @brief Power-on the LED for duration
	 * 
	 * @param time : time in millisecond
	 */
	void on(unsigned long time);

	/**
	 * @brief Use PWM output
	 * 
	 * @param value : PWM value
	 */
	void pwm(byte value);

	/**
	 * @brief Use PWM output for duration
	 * 
	 * @param value : PWM value
	 * @param time : time in millisecond
	 */
	void pwm(byte value, unsigned long time);

	/**
	 * @brief Blink the LED
	 * 
	 * @param timeHigh : time for HIGH state in ms
	 * @param timeLow : time for LOW state in ms
	 * @param repeat : Count of repetition
	 */
	void blink(unsigned long timeHigh, unsigned long timeLow, unsigned long repeat);

	/**
	 * @brief Power-off the LED
	 * 
	 */
	void off();
	
private:
	byte _led;

};

#endif