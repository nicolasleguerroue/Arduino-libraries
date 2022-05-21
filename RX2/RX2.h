/**
 * 
 *
 */

#include <Arduino.h>
#include <RS232.h>
#include <UART.h>

//Speeds configurations
#define LOW_SPEED 9600 //Low speed 
#define HIGH_SPEED 115200 //Low speed 
#define LOCKED 0x00


#define RELAY_1 0x02 //Relay pin
#define RELAY_2 0x03 //Relay pin

#define RED 0x04 //Red pin -> PWM
#define GREEN 0x05 //Red pin -> PWM
#define BLUE 0x06 //Red pin - PWM

#define TEMPERATURE 0x07 //LM35 pin
#define IR 0x08 //IR sensor pin

#define RX 0x09 //IR sensor pin
#define TX 0x0A //IR sensor pin



 




class RX2 {//define new class

	public: //public function
        
        RX2();//Constructor
		void begin(unsigned long speed); //Initialize new parameters    
		void debug(); //Prevent some errors
		float getTemperature(); //Get temperature from LM35  	
		String getBluetooth(); //Get bluetooth data from HC_05
		void sendBluetooth();
		String getComputer(); //Get bluetooth data from HC_05
		String getComputer(byte state); //Get bluetooth data from HC_05
		void sendComputer(String data);
		void sendComputer(int data);
		float getLight(); //get level light from LDR (0 to 100)
		void display(); //display text to LCD screen



    private:

    	char _c; //Char used in order to assembly new string
    	String _message; // Used to save new string
    	RS232 _computer;



};



