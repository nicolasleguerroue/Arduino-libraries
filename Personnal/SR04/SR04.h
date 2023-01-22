/**
 * @file SR04.h
 * @author Nicolas Le Guerroué
 * @brief 
 * @version 1.0
 * @date 2023-01-22
 */

#include "Arduino.h"

#define M 1
#define CM 2

/**
 * @brief SR04 class
 * 
 */
class SR04
{
public:
	/**
	 * @brief Construct a new SR04 object
	 * 
	 * @param trig 
	 * @param echo 
	 */
	SR04(int trig, int echo);

	/**
	 * @brief Get the range of target
	 * 
	 * @param unite 
	 * @return float 
	 */
	float read(int unite);
	 
private: 
	int _trig;
	int _echo;
	float _reading_echo = 0;
	float _cm = 0;
	
};