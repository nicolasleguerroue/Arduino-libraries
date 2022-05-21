// Bibliothèque RS232 pour communication UART natif
// AUTEUR : Nicolas LE GUERROUE
#include "Arduino.h"
#define LOCKED 0
#define RPI 115200
#define HC_05 9600
#define CRIUS 115200

class RS232 		//DEBUT CLASSE RS232
{
public:

   RS232();
   void begin(unsigned long bauds);
   String read(void);//lit les données
   String read(uint8_t position);//lit les données et attend qu'il y en ait
   void send(String message); //envoie les données (String)
   void send(int message);//envoie les données (int)

private:


   	char c;
   	String message;
   
};   //FIN CLASSE RS232


