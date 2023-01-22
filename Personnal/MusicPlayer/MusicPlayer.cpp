#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(uint8_t pinBuzzer)
{
    _pinBuzzer = pinBuzzer;
    pinMode(_pinBuzzer, OUTPUT);
}

void MusicPlayer::play()
{

    //WAit data before start
    String header = "";
    do 
    {
      header = uartDevice->read(WAIT_DATA);
      if(header[0]==_startMelodyOrder[0])
      {
        break;
      }
      delay(1);
      }
    while(header!=_startMelodyOrder);
        
    int size = sizeof(melodyMario) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      String message = uartDevice->read();
      if(message[0] == _endMelodyOrder[0])
      {
        break;
      }
      int noteDuration = 1000 / tempoMario[thisNote];
      this->buzz(melodyMario[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      this->buzz(0, noteDuration);

    }//End for

}//End play


void MusicPlayer::demo()
{

        
    int size = sizeof(melodyMario) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      int noteDuration = 1000 / tempoMario[thisNote];
      this->buzz(melodyMario[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      this->buzz(0, noteDuration);

    }//End for

}//End play

void MusicPlayer::addUARTDevice(UART *uart, String startMelodyOrder,String endMelodyOrder)
{
    uartDevice = uart;
    _startMelodyOrder = startMelodyOrder;
    _endMelodyOrder = endMelodyOrder;
}

void MusicPlayer::buzz(long frequency, long length) {


  long delayValue = 1000000 / frequency / 2;
  long numCycles = frequency * length / 1000; 

  for (long i = 0; i < numCycles; i++) 
  { 
    digitalWrite(this->_pinBuzzer, HIGH); 
    delayMicroseconds(delayValue*0.6);
    digitalWrite(this->_pinBuzzer, LOW);
    delayMicroseconds(delayValue*0.6); 
  }

}
