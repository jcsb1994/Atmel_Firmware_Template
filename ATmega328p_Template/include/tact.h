#include "app_config.h"
#ifndef TACT_H
#define TACT_H


/*##################################################
            MACROS
##################################################*/

// Debounce algorithm macros
#define DEBOUNCE_TIME 0.5
#define SAMPLE_FREQUENCY 10
#define MAXIMUM (DEBOUNCE_TIME * SAMPLE_FREQUENCY)

// Polling macros
#define SHORT_EFFECT_REQUIRED 1
#define RELEASE_EFFECT_REQUIRED 2
#define LONG_EFFECT_REQUIRED 3

/*##################################################
            DECLARATION
##################################################*/

void up_short(void);
void up_release(void);
void up_long(void);


void SPI_init();

struct input_shift_register
{
    int ID;
    uint8_t data;
    uint8_t *ptr_to_data;

};


class tact
{
public:

    tact(int assigned_pin, input_shift_register shift = {0,0,0}); // Constructor
    
    void debounce();
    short poll(bool debounce_flag);
    void activate();
    void setFunctions(void short_press_function(void), void release_press_function(void), void long_press_function(void));

    short state;

private:
    int pin;

    // Pointers to tact effect functions
    void (*short_ptr)(void);
    void (*release_ptr)(void);
    void (*long_ptr)(void);

    // Debounce static variables
    volatile unsigned int input; // Current state of the tact switch
    volatile unsigned int integrator;
    volatile bool btnOutput; // Output of the algorithm
    volatile bool lastOutput;

    volatile unsigned int tact_is_pressed; // Keeps track of which button is pressed during poll for long presses and others NVM!!

//#if LONG_BUTTON_PRESS_CONFIG
    volatile bool long_effect_done; // Flags when a long press was executed
//#if TACT_TIMER_INTERRUPT_CONFIG == WDT_USED // If a timer is checking tact, can be used to count time
    volatile unsigned int long_press_counter; // Keeps count of how long the tact has been pressed for

//#else
    volatile unsigned long last_press_millis;
//#endif
//#endif
};


#endif // Header guard