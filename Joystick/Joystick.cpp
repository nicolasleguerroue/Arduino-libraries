/* Bibliothèque Joystick by Nicolas LE GUERROUE
 */
#include "Joystick.h"
#include "Arduino.h"

Joystick::Joystick(int axe_x, int axe_y, int button, int type) { //Constructeur

		_axe_x=axe_x;
		_axe_y=axe_y;
		_button=button;
		_mode=type;

}//Fin constructeur

void Joystick::begin() {

	  pinMode(_axe_x, INPUT);
  	pinMode(_axe_y, INPUT);
  	if(_mode==INPUT_PULLUP) { pinMode(_button, INPUT_PULLUP); }
  	else { pinMode(_button, INPUT); }

}//Fin begin


void Joystick::setShortTime(int short_delay) {

	_short_delay = short_delay;

}//Fin setShortTime

void Joystick::setLongTime(int long_delay) {

	_long_delay = long_delay;

}//Fin setLongTime

int Joystick::read() {

	  int val_x = analogRead(_axe_x);
  	int val_y = analogRead(_axe_y);
  	bool state = digitalRead(_button);
 
	  if(val_x<(512+OFFSET) && val_y>MAX) 		{delay(BOUND);return UP;}
  	else if(val_x<(512+OFFSET) && val_y<MIN) 	{delay(BOUND);return DOWN;}
  	else if(val_x>MAX && val_y<(512+OFFSET)) 	{delay(BOUND);return LEFT;}
  	else if(val_x<MIN && val_y<(512+OFFSET)) 	{delay(BOUND);return RIGHT;}

  	else if(state==false and _mode==INPUT_PULLUP) 						{

  		int begin_time=millis();
  		int time=0;

  		do{

  			state = digitalRead(_button);
  			time=millis();

  		}while(state==false);

  		if(time-begin_time >_long_delay)  {delay(BOUND);return LONG_PUSH;}
  		else if(time-begin_time >_short_delay)  {delay(BOUND);return SHORT_PUSH;}
  		else {return CENTER;}

  	}//Fin else if

    else if(state==true and _mode!=INPUT_PULLUP)             {

      int begin_time=millis();
      int time=0;

      do{

        state = digitalRead(_button);
        time=millis();

      }while(state==true);

      if(time-begin_time >_long_delay)  {delay(BOUND);return LONG_PUSH;}
      else if(time-begin_time >_short_delay)  {delay(BOUND);return SHORT_PUSH;}
      else {return CENTER;}

    }//Fin else if
    
    else {return VOID;}
	
}//Fin read
