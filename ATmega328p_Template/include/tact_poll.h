#ifndef POLL_BUTTONS_H
#define POLL_BUTTONS_H

#include "app_config.h"




/***************************************************************************
 * 
 * poll buttons
 * 
 ***************************************************************************/
extern volatile bool refresh_flag;

#if LONG_BUTTON_PRESS_CONFIG == 1
extern volatile int long_press_counter;
extern volatile int pressed_button_semaphore;
#endif



/*##################################################
            FUNCTIONS
##################################################*/

/***************************************************************************
 * pollButtons function
 * 
 * This function must be called for every button in the application on every loop interation.
 * It targets only 1 pin.
 *
 ***************************************************************************/

void pollButton(int pin);



#endif