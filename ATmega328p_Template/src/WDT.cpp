#include "WDT.h"

#if WDT_INTERRUPT_CONFIG

volatile uint8_t wdt_counter;   // Volatile is preferable when modified in WDT

/*##################################################
            FUNCTIONS
##################################################*/

void WDT_setup()
{
    //WATCHDOG TIMER SETUP
    
    WDTCSR = (24);      // Change enable and WDE - also resets

    //prescalers only - get rid of the WDE and WDCE bit.
    
    #if WDT_PERIOD == 125
    WDTCSR = (3);        // 0,125 sec
    #elif WDT_PERIOD == 32
    WDTCSR = (1);       //32 ms
    #elif WDT_PERIOD == 16
    WDTCSR = (0);  
    #endif

    WDTCSR |= (1 << 6); //enable interrupt mode - WDT as an interrupt is useful to wake up from sleep

}

ISR(WDT_vect)
{
    wdt_counter++;
}

#endif