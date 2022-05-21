// Bibliothèque Utils pour utiliser des focntions spécifiques
// AUTEUR : Nicolas LE GUERROUE
#include "Arduino.h"


class Point {

public:

  Point(); // constructeur
  int getX();//lire x
  int getY(); //lit y
  void setX(int x);//définir x
  void setY(int y);//définir y
  void write(int x, int y);
  

 private:

 	int _x = 0;
 	int _y = 0;

};//FINC CLASSE UTILS
