#include "app_config.h"

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

extern int interface[];

class tact
{
public:
    tact(int assigned_pin); // Constructor
    
    void debounce();
    short poll(bool debounce_flag);
    void activate();
    void setFunctions(void short_press_function(), void release_press_function(), void long_press_function());

    short state;

private:
    int pin;

    // Pointers to tact effect functions
    void (*short_ptr)();
    void (*release_ptr)();
    void (*long_ptr)();

    // Debounce static variables
    volatile unsigned int input; // Current state of the tact switch
    volatile unsigned int integrator;
    volatile bool btnOutput; // Output of the algorithm
    volatile bool lastOutput;

    volatile unsigned int tact_is_pressed; // Keeps track of which button is pressed during poll for long presses and others NVM!!

#if LONG_BUTTON_PRESS_CONFIG
    volatile bool long_effect_done; // Flags when a long press was executed
#if WDT_INTERRUPT_CONFIG == 1 // If WDT is ON, whether for sleep or not, can be used to count time
    volatile unsigned int long_press_counter; // Keeps count of how long the tact has been pressed for
#else
    volatile unsigned long last_press_millis;
#endif
#endif
};
