
#ifndef DEBOUNCE_H
#define DEBOUNCE_H  


#include "app_config.h"

// Debounce algorithm
#define DEBOUNCE_TIME 0.5
#define SAMPLE_FREQUENCY 10
#define MAXIMUM (DEBOUNCE_TIME * SAMPLE_FREQUENCY)
#define NUMBER_OF_PINS_TO_DEBOUNCE  13

/***************************************************************************
 * 
 * debounce
 * 
 ***************************************************************************/

extern volatile unsigned int input;
extern volatile unsigned int integrator[];
extern volatile bool btnOutput[];
extern volatile bool screenFlag;
extern volatile bool lastOutput[];

void debounce(uint8_t pin); //needs to be void because isn't returning anything when integrator has value 1 or 2

#endif