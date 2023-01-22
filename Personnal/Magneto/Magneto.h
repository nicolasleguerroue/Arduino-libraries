/**
 * @file Magneto.h
 * @author Nicolas Le Guerroué (nicolasleguerroue@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2023-01-22
 * 
 */

#ifndef MAGNETO_H
#define MAGNETO_H

#include "Arduino.h"
#include "CapPin.h"

/**
 * @brief Magneto class
 * 
 */
class Magneto
{
public:
	/**
 	 * @brief Construct a new Magneto object
 	 * 
 	 * @param pin 
 	 */
	Magneto(uint8_t pin);

	/**
	 * @brief Debug method
	 * 
	 */
	void debug();

	/**
	 * @brief Check if wire is touched
	 * 
	 * @return boolean 
	 */
	bool read(void);


	
private:

 	CapPin CapSense;
	
};//End Magneto class

#endif