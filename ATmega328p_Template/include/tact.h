#ifndef TACT_H
#define TACT_H

#include "main.h"
#include "74HC165.h"

/*##################################################
            MACROS
##################################################*/

// Debounce macros
#define DEBOUNCED 1
#define NOT_DEBOUNCED 0
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

class tact
{
public:
    tact(int assigned_pin);                              // Constructor
    tact(int assigned_pin, input_shift_register &shift); // Overloaded constructor for tacts linked to a shift register chip

    void debounce();
    short poll(bool debounce_flag);
    void activate();

#if SIMULTANEOUS_BUTTON_PRESSES_CONFIG
    void timerCount();
<<<<<<< HEAD

#else
    static void timerCount();
#endif

    void setFunctions(void short_press_function(), void release_press_function(), void long_press_function());
=======
    void setFunctions(void short_press_function(void), void release_press_function(void), void long_press_function(void));

>>>>>>> parent of b02994b... usable but setFunctions needs 3 arguments
    short state;

private:
    int pin;
    static int mCount;
    unsigned int mID;

    bool input_shift_used;
    input_shift_register *input_shift_ptr;

    // Pointers to tact effect functions
    void (*short_ptr)();
    void (*release_ptr)();
    void (*long_ptr)();

    // Debounce variables
    volatile unsigned int input; // Current state of the tact switch
    volatile unsigned int integrator;
    volatile bool btnOutput; // Output of the algorithm
    volatile bool lastOutput;

    // Press and long press variables (multiple simultaneous presses version)
#if SIMULTANEOUS_BUTTON_PRESSES_CONFIG
    volatile unsigned int tact_is_pressed; // Keeps track if button is pressed during poll
#if LONG_BUTTON_PRESS_CONFIG
    volatile bool long_effect_done;           // Flags when a long press was executed
#if TACT_TIMER_INTERRUPT_CONFIG               // If a timer is checking tact, can be used to count time
    volatile unsigned int long_press_counter; // Keeps count of how long the tact has been pressed for
#else
    volatile unsigned long last_press_millis;
#endif // TACT_TIMER_INTERRUPT_CONFIG
#endif // LONG_BUTTON_PRESS_CONFIG

    // Press and long press variables (single press at a time version)
#else //no simultaneous button presses
    static unsigned int tact_is_pressed;    // Keeps track of which button is pressed during poll
#if LONG_BUTTON_PRESS_CONFIG
    static  bool long_effect_done;           // Flags when a long press was executed
#if TACT_TIMER_INTERRUPT_CONFIG // If a timer is checking tact, can be used to count time
    static unsigned int long_press_counter; // Keeps count of how long the tact has been pressed for
#else
    static unsigned long last_press_millis;
#endif // TACT_TIMER_INTERRUPT_CONFIG
#endif // LONG_BUTTON_PRESS_CONFIG
#endif // SIMULTANEOUS_BUTTON_PRESSES_CONFIG
};

#endif // Header guard