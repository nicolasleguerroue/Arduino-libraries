
#include <Arduino.h>
#include "RX2.h"


RX2::RX2()
{


}

void RX2::begin(unsigned long speed)
 {

	_computer.begin(speed);
	delay(100);
	_computer.send("COMMUNICATION RX2 : [OK]");
	

}

void RX2::debug() {

}

float RX2::getTemperature() {

}

String RX2::getBluetooth() {

}

void RX2::sendBluetooth() {

}

String RX2::getComputer() {

	_message = _computer.read();
	return _message;

}

String RX2::getComputer(byte state) {

	_message = _computer.read(state);
	return _message;

}

void RX2::sendComputer(int data) {

	
	_computer.send(data);
}

void RX2::sendComputer(String data) {

	_computer.send(data);
}

float RX2::getLight() {

}

void display() {


}


