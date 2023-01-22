/**
 * @file RS232.h  
 * @author Nicolas LE GUERORUE
 * @brief 
 * @version 1.0
 * @date 2022-12-01
 * 
 */
#ifndef RS232_H
#define RS232_H

#include "Arduino.h"

#define CRIUS 115200
#define HC_05 9600
#define XBEE_9600 9600
#define XBEE_115200 115200

#define WAIT_DATA 1
#define NO_WAIT_DATA 0

class RS232 		
{
public:

	/**
	 * @brief Construct a new RS232 object
	 * 
	 */
   	RS232();   

	/**
	 * @brief Read data from device
	 * 
	 * @return String 
	 */
   	String read(void);                    //Read data

	/**
	 * @brief Read data from device and if WAIT_DATA is given in arg, wait data befor return message/ See also setExitTime method 
	 * 
	 * @param waitData 
	 * @return String 
	 */
   	String read(bool waitData);           //wait data before return string

	/**
	 * @brief Init communication
	 * 
	 * @param bauds : Baudrate 
	 */
    void begin(unsigned long bauds);      //Init communication

	/**
	 * @brief Send String data
	 * 
	 * @param message : String data
	 */
   	void send(String message);            //Send data 

	/**
	 * @brief Send Integer data
	 * 
	 * @param message : Integer data
	 */
   	void send(int message);               //Send data

	/**
	 * @brief Set the Exit Time object. If WAIT_DATA given in read method, exit method after exitTime ms
	 * 
	 * @param exitTime 
	 */
    void setExitTime(uint16_t exitTime);  //Update exit time of read(1) method
     
private:

 	
   	char c;
   	unsigned long _bauds;
    uint16_t _exitTime = 100;

}; //End RS232 class

#endif
