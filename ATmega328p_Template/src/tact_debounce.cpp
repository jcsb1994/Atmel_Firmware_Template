#include "tact_debounce.h"

/***************************************************************************
 * 
 * variables used for the debounce algorithm
 * 
 ***************************************************************************/

volatile unsigned int input; // 0 or 1 depending on the input signal
volatile unsigned int integrator[NUMBER_OF_PINS_TO_DEBOUNCE];
volatile bool btnOutput[NUMBER_OF_PINS_TO_DEBOUNCE];
volatile bool screenFlag;
volatile bool lastOutput[NUMBER_OF_PINS_TO_DEBOUNCE];



/*##################################################
            FUNCTIONS
##################################################*/

void debounce(unsigned char pin)
{

  input = digitalRead(pin);
  
  //STEP 1
  if (input == 0)
  {
    if (integrator[pin] > 0)
      integrator[pin]--;
  }
  else if (integrator[pin] < MAXIMUM)
    integrator[pin]++;


  //STEP 2
  if (integrator[pin] == 0)
    btnOutput[pin] = 0;
  else if (integrator[pin] >= MAXIMUM)
  {
    integrator[pin] = MAXIMUM; // defensive code if integrator got corrupted
    btnOutput[pin] = 1;
  }
}