//BIBLIOTHEQUE UTILS
#include "Arduino.h"
#include "Point.h"

Point::Point(){}
  
int Point::getX() {

  return _x;

}

int Point::getY() {

  return _y;

}

void Point::setX(int x) {

  _x=x;

}

void Point::setY(int y) {

  _y=y;

}

void Point::write(int x, int y) {

	_x=x;
	_y=y;
}




//FIN BIBLIOTHEQUE Point