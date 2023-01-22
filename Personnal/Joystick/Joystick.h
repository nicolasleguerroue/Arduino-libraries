/**
 * @file Joystick.h
 * @author Nicolas LE GUERROUE
 * @brief 
 * @version 1.0
 * @date 2023-01-22
 * 
 */
#ifndef JOYSTICK_H
#define JOYSTICK_H

#define LOCKED_JOYSTICK 0xff  		

#define UP 0xf0 		
#define DOWN 0xf1 		
#define RIGHT 0xf2 		
#define LEFT 0xf3 		
#define CENTER 0xf4 	
#define SHORT_PUSH 0xf5
#define LONG_PUSH 0xf6
#define VOID 0xf7

#define OFFSET 50 		
#define MAX 900 		
#define MIN 150 		
#define BOUND 10   

#define SHORT_DELAY 200 	
#define LONG_DELAY 2000		

/**
 * @brief Joystick class
 * 
 */
class Joystick
{
public:

	/**
	 * @brief Construct a new Joystick object
	 * 
	 * @param axe_x 
	 * @param axe_y 
	 * @param button 
	 * @param type 
	 */
	Joystick( int axe_x, int axe_y, int button, int type); 

	/**
	 * @brief Init Joystick
	 * 
	 */
  	void begin();
	/**
	 * @brief Set the Short Time object
	 * 
	 * @param short_delay 
	 */
	void setShortTime(int short_delay); 	

	/**
	 * @brief Set the Long Time object
	 * 
	 * @param long_delay 
	 * @return * void 
	 */
	void setLongTime(int long_delay);

	/**
	 * @brief read value of joystick
	 * 
	 * @return int 
	 */
	int read(); 	



private:

	int _button=0;
	int _axe_x=0;
	int _axe_y=0;
	int _mode=0;

	int _short_delay = 100;
	int _long_delay = 400;

	
};


#endif
