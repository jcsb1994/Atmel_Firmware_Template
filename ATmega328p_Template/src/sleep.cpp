<<<<<<< HEAD
#include "sleep.h"

#if SLEEP_CONFIG

void sleep_setup() {  
    
    SMCR |= (1 << 2);                           //power down mode
    SMCR |= 1;                                  //enable sleep
    ADCSRA |= (1 << 7);                         //Disable ADC (saves additional power)
=======
    #include "sleep.h"
    
void sleep_setup() {  
    
    //ADCSRA |= (1 << 7); // Disable ADC - don't forget to flip back after waking up if using ADC in your application
    // To turn it back ON: ADCSRA &= ~(1 << 7);

    //ENABLE SLEEP - this enables the sleep mode
    SMCR |= (1 << 2); //power down mode
    SMCR |= 1;        //enable sleep
>>>>>>> parent of b02994b... usable but setFunctions needs 3 arguments
}

void activate_sleep()
{
    
<<<<<<< HEAD
    MCUCR |= (3 << 5);                         //set both BODS and BODSE at the same time
    MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6);    //then set the BODS bit and clear the BODSE bit at the same time
    //ADCSRA |= (1 << 7);                      //Disable ADC (saves additional power)
    __asm__ __volatile__("sleep");             //in line assembler to go to sleep
    //ADCSRA &= ~(1 << 7);                     //Enable ADC after sleep (if used)

}
=======
    MCUCR |= (3 << 5);                      //set both BODS and BODSE at the same time
    MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6); //then set the BODS bit and clear the BODSE bit at the same time
    __asm__ __volatile__("sleep");          //in line assembler to go to sleep
    ADCSRA |= (1 << 7);                     //re enable ADC? not sure
>>>>>>> parent of b02994b... usable but setFunctions needs 3 arguments

}