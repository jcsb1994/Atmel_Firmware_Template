#ifndef WDT_H
#define WDT_H

#include "app_config.h"


/*##################################################
            WDT
##################################################*/

extern volatile uint8_t wdt_counter;

/***************************************************************************
 * WDT_setup function
 * 
 * This function sets the appropriate registers for WDT to be turned on.
 * 
 ***************************************************************************/

void WDT_setup();

/*##################################################
            TIMER1
##################################################*/

void timer1_setup();

#endif