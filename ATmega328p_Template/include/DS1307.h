#ifndef REALTIME_H
#define REALTIME_H

#include "main.h"
#include <RTClib.h>

#define REAL_TIME_CLOCK_NAME_CONFIG RTC

/***************************************************************************
 * 
 * RTC
 * 
 ***************************************************************************/

//extern int data;

//extern RTC_DS1307 REAL_TIME_CLOCK_NAME_CONFIG; // Object created

/***************************************************************************
 * setup function
 * 
 * This function sets up the RTC and uploads current time at setup.
 * 
 ***************************************************************************/

void DS1307_setup();

#endif