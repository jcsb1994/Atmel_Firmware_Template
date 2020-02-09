#include "input_shiftReg.h"

int nb_of_input_shift_reg_objects;

input_shift_reg::input_shift_reg()
{
    shift_ID = nb_of_input_shift_reg_objects++;
}

void SPI_init()
{
    SPI.setClockDivider(SPI_CLOCK_DIV128);
    SPI.setDataMode(SPI_MODE0);
    SPI.setBitOrder(MSBFIRST);
    SPI.begin();
}

void inputShiftSnapShot()
{
    //take a 74hc165 snapshot: tells the 165 to check if any inputs (tact switched) where HIGH or LOW at this given moment
    PORTD &= ~(1 << loadPin);
    delay(1);
    PORTD ^= (1 << loadPin);
    
for(int i = 0; i < nb_of_input_shift_reg_objects; i++)
{
    //something needs to point in order to the shift registers as loop iterates
    data = SPI.transfer(0x00);
}

#ifdef FIRST_INPUT_SHIFT_NAME_CONFIG
    FIRST_INPUT_SHIFT_NAME_CONFIG.data = SPI.transfer(0x00);
#endif

#ifdef SECOND_INPUT_SHIFT_NAME_CONFIG
    SECOND_INPUT_SHIFT_NAME_CONFIG.data = SPI.transfer(0x00);
#endif

#ifdef THIRD_INPUT_SHIFT_NAME_CONFIG
    THIRD_INPUT_SHIFT_NAME_CONFIG.data = SPI.transfer(0x00);
#endif

#ifdef FOURTH_INPUT_SHIFT_NAME_CONFIG
    FOURTH_INPUT_SHIFT_NAME_CONFIG.data = SPI.transfer(0x00);
#endif
}