/**
 * @file UART.h
 * @author Nicolas LE GUERROUE (nicolasleguerroue@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2022-11-29
 * 
 * @copyright 
 * 
 */
#ifndef UART_H
#define UART_H

#include "Arduino.h"
#include "SoftwareSerial.h"

#define CRIUS 115200
#define HC_05 9600
#define XBEE_9600 9600
#define XBEE_115200 115200

#define WAIT_DATA 1
#define NO_WAIT_DATA 0

class UART 		
{
public:

	/**
	 * @brief Construct a new UART object
	 * 
	 * @param rx_device : RX pin of UART device
	 * @param tx_device : TX pin of UART device
	 */
   	UART(int rx_device, int tx_device);   //Rx of module (Xbee, Crius...) then Tx)

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

  	SoftwareSerial _serial;
  	
   	char c;
   	unsigned long _bauds;
    uint16_t _exitTime = 100;

}; //End UART class

#endif
