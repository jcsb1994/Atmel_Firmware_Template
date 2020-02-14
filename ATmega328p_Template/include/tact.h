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


struct input_shift_register
{
    bool not_used;
    int data;
    int *ptr_to_data;

};

void input_shift_reg_SPI_init();

void shift_reg_snapshot();

int transfer_shift_reg_data();





class tact
{
public:

    tact(int assigned_pin); //Constructor
    tact(int assigned_pin, input_shift_register& shift); // Overloaded constructor for tacts linked to a shift register chip
    
    void debounce();
    //void debounce(input_shift_register& linked_shift);
    short poll(bool debounce_flag);
    void activate();
    void timerCount();
    void setFunctions(void short_press_function(void), void release_press_function(void), void long_press_function(void));
    short state;

private:
    int pin;

    bool input_shift_used;
    //input_shift_register input_shift;
    input_shift_register* input_shift_ptr;
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