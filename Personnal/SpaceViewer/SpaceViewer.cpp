/**
 * @file SpaceViewer.cpp
 * @author Nicolas LE GUERROUE (nicolasleguerroue@gmail.com) 
 * @brief 
 * @version 1.0
 * @date 2022-11-29
 * 
 * @copyright 
 * 
 */
#include "SpaceViewer.h"

SpaceViewer::SpaceViewer() {}


static String SpaceViewer::getSpacePosition(float relativeRoll, float relativePitch)
{
  String message = "";
  if(relativePitch > TRIGGER_LEFT) 
  {
    message += '1';
  }
  else {
    message += '0';    
  }
  if(relativePitch < TRIGGER_RIGHT) 
  {
    message += '1';
  }
  else {
    message +='0';
  }

  //
  if(relativeRoll >= TRIGGER_FORWARD) 
  {
    message += '1';
  }
  else {
    message += '0';    
  }

  if(relativeRoll < TRIGGER_BACKWARD) 
  {
    if(message[0]=='1' || message[1]=='1')
    {
      message += '0';
    }
    else {
      message += '1';
    }
    
  }
  else {
    message += '0';    
  }

    
  return message;
  
  /*
  if(relativePitch > TRIGGER_LEFT) 
  {
    message += '1';
    message += '0';
    if(relativeRoll >= TRIGGER_FORWARD) 
    {
      message += '1';
      message += '0';
    }
    else {
      message += '0';
      message += '0';      
    }
  }
  else if(relativePitch < TRIGGER_RIGHT)
  {
    message += '0';
    message += '1';   
    if(relativeRoll >= TRIGGER_FORWARD) 
    {
      message += '1';
      message += '0';
    }
    else {
      message += '0';
      message += '0';      
    }
  }
  else {//If forward
    
    message += '0';
    message += '0';
    if(relativeRoll >= TRIGGER_FORWARD) 
    {
      message += '1';
      message += '0';
    }
    else if(relativeRoll < TRIGGER_BACKWARD)
    {
      message += '0';
      message += '1';    
    }
    else {
      message += '0';
      message += '0';       
    }
  
  }//End else
  */

  //return message;

}
