

#ifndef GAIT_SPEED_ASSESS_H
#define GAIT_SPEED_ASSESS_H

#include "main.h"

class gaitSpeedAssess
{
private:
    uint8_t mTestType = 5; // 3 possible types; 3mWT, 4mWT or 5mWT

public:

    int exactDistance = 500;    // Takes values from 3 to 5 meters: 300 to 500 in cm

    gaitSpeedAssess() {} //ctor
    uint8_t getTestType()
    {
        return mTestType;
    }
    void setTestTypeUp()
    {
        //mTestType = 5;
        if (mTestType < 5)
            mTestType++;
        //Serial.println(mTestType);
    }
    void setTestTypeDown()
    {
        if (mTestType > 3)
            mTestType--;
        //Serial.println(mTestType);
    }
};

extern gaitSpeedAssess gait_assessment;

#endif
