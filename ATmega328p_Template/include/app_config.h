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



/***************************************************************************
 * USED PINS ON THE ATMEGA328P
 ***will now be declared in main
 ***************************************************************************/

/***************************************************************************
 * BUTTONS (TACT SWITCHES) MACROS
 * 
 ***************************************************************************/

#define BUTTON_ACTIVE_STATE_CONFIG 0 // 1 for active HIGH buttons or 0 for active low

#define SHORT_BUTTON_PRESS_CONFIG 1 // 1 to turn ON functionality for short button presses
#define BUTTON_RELEASE_CONFIG 1     // 1 to turn ON functionality for button releases
#define LONG_BUTTON_PRESS_CONFIG 1          // 1 to turn ON functionality for long button presses
#define RELEASE_AFTER_LONG_EFFECT_CONFIG 1  // 1 will trigger a release effect even after long press effects occured

#define TACT_TIMER_INTERRUPT_CONFIG WDT_USED    // Set up if there is an ISR managing tacts (polling,debouncing, long presses) WDT_USED, etc
#define TACT_TIMER_PERIOD   WDT_PERIOD  // Set up the period of the timer used for tact
#define LONG_PRESS_DELAY 1000  // Set up desired time before long presses are triggered in milliseconds

#define ITERATIONS_TO_LONG_PRESS_TRIGGER LONG_PRESS_DELAY / TACT_TIMER_PERIOD


/***************************************************************************
 * 74HC165 PINS
 * MISO   -   pin 12 to Q7 (pin9) of last shift register
 * SCK    -   pin 13 to CP (pin2) on registers
 * LOAD   -   digital OUTPUT pin of microcontroller to PL (pin1) on registers. 
 ***************************************************************************/
#define loadPin 3
#define LOAD_PIN_PORT_DATA_DIRECTION_REG DDRD
#define LOAD_PIN_PORT_STATE_REG PORTD
//#define TACT_INPUT_SHIFT_REG 0

/***************************************************************************
 * WDT period
 * acceptable values in ms:
 * 16, 32, 64, 125, 250, 500, 1000, 2000, 4000 and 8000
 * leave any value if unused, do not undefine
 ***************************************************************************/

#define WDT_CONFIG 1

#define WDT_PERIOD 16 // WDT period in microseconds, or from other timer chosen

/*##################################################################
CONSTANT MACROS (DO NOT EDIT)
##################################################################*/

#define DEBOUNCED 1
#define NOT_DEBOUNCED 0

#define TIMER0_USED 1
#define TIMER1_USED 2
#define TIMER2_USED 3
#define WDT_USED 4


// End of File
#endif