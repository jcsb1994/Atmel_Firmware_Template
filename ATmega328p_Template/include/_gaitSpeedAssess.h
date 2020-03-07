#ifndef GAIT_SPEED_ASSESS_H
#define GAIT_SPEED_ASSESS_H

#include "main.h"

class gaitSpeedAssess
{
private:
    uint8_t mTestType;  // 3 possible types; 3mWT, 4mWT or 5mWT
    int mExactDistance;  // Takes values from 3 to 5 meters: 300 to 500 in cm


public:
    gaitSpeedAssess(/* args */);
    ~gaitSpeedAssess();
};

gaitSpeedAssess::gaitSpeedAssess(/* args */)
{
}

gaitSpeedAssess::~gaitSpeedAssess()
{
}

extern gaitSpeedAssess gait_assessment;


#endif