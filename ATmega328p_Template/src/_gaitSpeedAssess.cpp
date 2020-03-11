
#include "_gaitSpeedAssess.h"

unsigned long gaitSpeedAssess::computeSpeed()
{
    unsigned long chrono = millis() - mStartTime;
    mStartTime = 0;
    return chrono;
}

gaitSpeedAssess gait_assessment;
