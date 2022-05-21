// Bibliothèque RGB by Nicolas LE GUERROUE
#include "Arduino.h"

#define RED 0
#define GREEN 1
#define BLUE 2
#define CYAN 3
#define ORANGE 4
#define WHITE 5
#define PURPLE 6
#define TURQUOISE 7
#define YELLOW 8
#define MAGENTA 9
#define ROSE 10

class RGB 			 //DEBUT CLASSE RGB
{
public:

RGB(int pin_red, int pin_green, int pin_blue);	
void on(int color);//affiche la couleur en argument
void blink(int color, unsigned long delai_high, unsigned long delai_low,unsigned long nombre);//fait clignoter la couleur
void off();//eteint la led
void randomRGB(unsigned long delai, int frequence);//affiche toutes les couleurs de manière aléatoire (delai en ms et f en Hz)

private:
int pin_redIN;
int pin_greenIN;
int pin_blueIN;

};   ///FIN CLASSE RGB
