//BIBLIOTHEQUE UTILS
#include "Arduino.h"
#include "Utils.h"

Utils::Utils(){}
  
int Utils::analog(byte ENTREE, int nb_read) {

  pinMode(ENTREE, INPUT);
  for(int i =0; i<nb_read; i++) {
  valeur = analogRead(ENTREE);
  somme = somme + valeur;
  }
  valeur = (somme/nb_read);
  return valeur;

}


float Utils::batterie(byte PONT_DIVISEUR, float coefficient) {

  pinMode(PONT_DIVISEUR, INPUT);
  float valeur = analogRead(PONT_DIVISEUR);
  float tension = ((valeur*5)/1024)*coefficient;
  return(tension);

}

float Utils::temperature_from_LM35(byte pin_LM35) {

  pinMode(pin_LM35, INPUT);
  float valeur = analogRead(pin_LM35);
  float tension = (valeur*1024.0)/1024.0;
  float temp = tension/10;
  return temp;
}

bool Utils::buttonIsPushed(int button_pin, int config_button) {

  switch(config_button) {

    case 1:   pinMode(button_pin, INPUT);
              if(digitalRead(button_pin)==1) {return false;}
              else {return true;}
                      
    case 2:   pinMode(button_pin, INPUT_PULL_UP);
              if(digitalRead(button_pin)==1) {return false;}
              else {return true;}
                      
    case 3:   pinMode(button_pin, INPUT);
              if(digitalRead(button_pin)==0) {return false;}
              else {return true;}
                     
  }//fin switch
}//fin buttonIsPushed



//FIN BIBLIOTHEQUE UTILS