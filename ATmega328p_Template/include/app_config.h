#ifndef APP_CONFIG_H
#define APP_CONFIG_H

/***************************************************************************
 * embedded utilz
 *tact, WDT, Sleep
 ***************************************************************************/

#include <Arduino.h>
#include <SPI.h>

#include "tact.h"
#include "WDT.h"
#include "sleep.h"

/*##################################################################
CONSTANT MACROS (DO NOT EDIT)
##################################################################*/

#define DEBOUNCED 1
#define NOT_DEBOUNCED 0

#define TIMER0_USED 1
#define TIMER1_USED 2
#define TIMER2_USED 3
#define WDT_USED 4

/***************************************************************************
 * USED PINS ON THE ATMEGA328P
 ***will now be declared in main
 ***************************************************************************/

/***************************************************************************
 * BUTTONS (TACT SWITCHES) MACROS
 * 
 ***************************************************************************/

#define BUTTON_ACTIVE_STATE_CONFIG 0 // 1 for active HIGH buttons or 0 for active low

#define SHORT_BUTTON_PRESS_CONFIG 0 // 1 to turn ON functionality for short button presses
#define BUTTON_RELEASE_CONFIG 1     // 1 to turn ON functionality for button releases

//#define LONG_PRESS_TIMER_CONFIG WDT


#define LONG_BUTTON_PRESS_CONFIG 1          // 1 to turn ON functionality for long button presses
#define LONG_PRESS_DELAY 1000               // Period in milliseconds before long presses are triggered

#define TACT_TIMER_INTERRUPT_CONFIG WDT_USED     // Set up if there is an ISR managing tacts

#define LONG_PRESS_COUNTER_DELAY WDT_PERIOD // 1 to turn ON functionality for long button presses
#define ITERATIONS_TO_LONG_PRESS_TRIGGER LONG_PRESS_DELAY / LONG_PRESS_COUNTER_DELAY



/***************************************************************************
 * INPUT SHIFT REGISTER
 *
 ***************************************************************************/

#define TACT_INPUT_SHIFT_REG 0

/***************************************************************************
 * INTERRUPT MACROS
 * 
 * WDT_SLEEP_INTERRUPT_CONFIG
 * 
 * 
 * WDT period
 * acceptable values in ms:
 * 16, 32, 64, 125, 250, 500, 1000, 2000, 4000 and 8000
 ***************************************************************************/

#define WDT_PERIOD 16 // WDT period in microseconds




// End of File
#endif