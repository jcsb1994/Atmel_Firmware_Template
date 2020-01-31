#ifndef APP_CONFIG_H
#define APP_CONFIG_H

#include <Arduino.h>

#include "tact_debounce.h"
#include "tact_poll.h"
#include "tact_actions.h"
#include "WDT.h"
#include "sleep.h"

/***************************************************************************
 * USED PINS ON THE ATMEGA328P
 *
 ***************************************************************************/

// Mechanical button pins
#define upPin 2
#define downPin 6


#define tft_power_pin 10

/***************************************************************************
 * BUTTONS (TACT SWITCHES) MACROS
 * 
 ***************************************************************************/

#define BUTTON_ACTIVE_STATE_CONFIG 1    // 1 for active HIGH buttons or 0 for active low

#define SHORT_BUTTON_PRESS_CONFIG 0 // 1 to turn ON functionality for short button presses
#define BUTTON_RELEASE_CONFIG 1 // 1 to turn ON functionality for button releases

#define LONG_BUTTON_PRESS_CONFIG 1  // 1 to turn ON functionality for long button presses
#define LONG_PRESS_DELAY 1000   // Period in microseconds before long presses are triggered
#define LONG_PRESS_COUNTER_DELAY WDT_PERIOD // 1 to turn ON functionality for long button presses
#define ITERATIONS_TO_LONG_PRESS_TRIGGER LONG_PRESS_DELAY / LONG_PRESS_COUNTER_DELAY

/***************************************************************************
 * INPUT SHIFT REGISTER
 *
 ***************************************************************************/

#define BUTTONS_INPUT_SHIFT_REG 0

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

#define WDT_SLEEP_INTERRUPT_CONFIG 1

#define WDT_PERIOD 16   // WDT period in microseconds



// End of File
#endif