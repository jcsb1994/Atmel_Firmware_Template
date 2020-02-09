#ifndef INPUT_SHIFTREG_H
#define INPUT_SHIFTREG_H

#include "app_config.h"
#include <stdint.h>
#include <SPI.h>

/***************************************************************************
 * 74HC165 PINS
 * MISO   -   pin 12 to Q7 of last shift register
 * SCK    -   pin 13 to CP on registers
 * LOAD   -   digital pin (2) to PL on registers. Needs to be set as output.
 ***************************************************************************/

#define loadPin 2
#define LOAD_PIN_PORT_DATA_DIRECTION_REG DDRD
#define LOAD_PIN_PORT_STATE_REG PORTD

class input_shift_reg
{
public:
    input_shift_reg();
    int shift_ID;
    int data;
    int *ptr_to_data;
};

/***************************************************************************
 * shift_reg struct
 ***************************************************************************/

typedef struct input_shift_register
{
    uint8_t data;
    uint8_t *ptr_to_data;

} input_shift;

/***************************************************************************
 * 
 * input shift register macros and input_shift instances
 * 
 ***************************************************************************/

#define NUMBER_OF_INPUT_SHIFT_REGISTERS 2
#define FIRST_INPUT_SHIFT_NAME_CONFIG button_shift
#define SECOND_INPUT_SHIFT_NAME_CONFIG hall_shift

extern input_shift FIRST_INPUT_SHIFT_NAME_CONFIG;
extern input_shift SECOND_INPUT_SHIFT_NAME_CONFIG;

/***************************************************************************
 * SPI_init function
 * 
 * SPI protocol is initialized.
 * SPI is needed to get data from the 74hc165 shift registers
 * 
 ***************************************************************************/

void SPI_init();

/***************************************************************************
 * inputShiftSnapShot function
 * 
 * 1) Turn the loadPin HIGH for a millisecond, saves the state of the input pins
 * at a given moment
 * 2) 1 empty byte is transfered for each shift register via the SPI protocol
 *    and received exchange byte is stored in the shift register's data member.
 * 
 ***************************************************************************/

void inputShiftSnapShot();

#endif