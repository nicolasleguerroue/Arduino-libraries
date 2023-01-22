/**
 * @file SpaceViewer.h
 * @author Nicolas LE GUERROUE (nicolasleguerroue@gmail.com) & Romain POSSEME
 * @brief 
 * @version 1.0
 * @date 2022-11-29
 * 
 * @copyright
 * 
 */

#ifndef SPACE_VIWER_H
#define SPACE_VIWER_H

#include "Arduino.h"


#define TRIGGER_FORWARD 25
#define TRIGGER_BACKWARD -25

#define TRIGGER_LEFT 25
#define TRIGGER_RIGHT -25

/**
 * @brief Class SpaceViewer used to compute relative position
 * 
 */
class SpaceViewer 		
{

public:

    /**
     * @brief Construct a new Space Viewer object
     * 
     */
   	SpaceViewer(); 

    /**
     * @brief Get the Space Position object
     * 
     * @param relativeRoll : Relative roll position
     * @param relativePitch : Relative Pitch position
     * @return String 
     */
    static String getSpacePosition(float relativeRoll, float relativePitch);

};


#endif