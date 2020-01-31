#include "app_config.h"

/*##################################################
            MACROS
##################################################*/

// Debounce algorithm macros
#define DEBOUNCE_TIME 0.5
#define SAMPLE_FREQUENCY 10
#define MAXIMUM (DEBOUNCE_TIME * SAMPLE_FREQUENCY)

/*##################################################
            DECLARATION
##################################################*/

class tact
{
public:
    tact(int assigned_pin); // Constructor
    void debounce();
    void poll();

private:
    int pin;

    // Debounce static variables
    volatile unsigned int input; // Current state of the tact switch
    volatile unsigned int integrator;
    volatile bool btnOutput; // Output of the algorithm
    volatile bool lastOutput;

    volatile unsigned int tact_is_pressed;    // Keeps track of which button is pressed during poll for long presses and others NVM!!
    volatile bool long_press_effect_flag;     // Flags when a long press was executed
    volatile unsigned int long_press_counter; // Keeps count of how long the tact has been pressed for
};

/*##################################################
            DEFINITIONS
##################################################*/

//volatile unsigned int tact::which_tact_is_pressed= 0; // Define it outside of the class declaration too.. Should keep the same value between all tact instances?
//volatile bool tact::long_press_effect_flag = 0; //storage classes like static cannot be declared during definition, just a point to remember

tact::tact(int assigned_pin)
{
    pin = assigned_pin; // Associate the pin to the private pin in the class
}

void tact::debounce()
{
    input = digitalRead(pin);

    //STEP 1
    if (input == 0)
    {
        if (integrator > 0)
            integrator--;
    }
    else if (integrator < MAXIMUM)
        integrator++;

    //STEP 2
    if (integrator == 0)
        btnOutput = 0;
    else if (integrator >= MAXIMUM)
    {
        integrator = MAXIMUM; // defensive code if integrator got corrupted
        btnOutput = 1;
    }
}

void tact::poll()
{

    /***************************************************************************
  * Option 1: The button "pin" was just pressed.
  * If it was LOW and now HIGH (active HIGH), action is activated and
  * refresh flag is set to refresh the screen. The semaphore value is set
  * to the current polled button.
  ***************************************************************************/
#if BUTTON_ACTIVE_STATE_CONFIG == 1
    if (btnOutput && !lastOutput)
    {
#elif BUTTON_ACTIVE_STATE_CONFIG == 0
    if (!btnOutput && lastOutput)
    {
#endif

        tact_is_pressed++; //button being polled is now flagged as pressed

#if SHORT_BUTTON_PRESS_CONFIG == 1
        //add a pressed effect here:
        shortSwitchActions(pin);
#endif
    }

    /***************************************************************************
  * Option 2: the button "pin" was just released.
  * ~ tact was marked as pressed on the last pull. Now 
  * check if buttons are active HIGH or LOW
  * if release is on, activate effect.
  * If debounced button is now LOW and was HIGH, its released so no long press effect is applied.
  ***************************************************************************/

#if BUTTON_ACTIVE_STATE_CONFIG == 1
    else if (lastOutput && !btnOutput)
    {
#elif BUTTON_ACTIVE_STATE_CONFIG == 0
    else if (!lastOutput && btnOutput)
    {
#endif

#if BUTTON_RELEASE_CONFIG == 1

        if (tact_is_pressed)

#if LONG_BUTTON_PRESS_CONFIG == 1
            if (!long_press_effect_flag) //if there was no long press. If there was, releasing will not trigger another effect
#endif
                //add a release effect here:
                releaseSwitchActions(pin);
#endif

#if LONG_BUTTON_PRESS_CONFIG == 1
            else //if long press effect occured
            {
                long_press_effect_flag = 0;
            }
#endif

        tact_is_pressed = 0;
    }

    /***************************************************************************
  * Option 3: Long press effect reached
  * The long_press_counter has reached a treshold time value and we are
  * polling the right button, which is pressed and marked with the semaphore.
  ***************************************************************************/

#if LONG_BUTTON_PRESS_CONFIG == 1
    else if (tact_is_pressed && long_press_counter >= ITERATIONS_TO_LONG_PRESS_TRIGGER)
    {

        longSwitchActions(pin);

        long_press_counter = 0; // Stop counting, flag up
        long_press_effect_flag++;
    }

    /***************************************************************************
  * Option 4: counting until long effect. 
  * This condition needs to be after "long effect reached" as it is true
  * even when the long press is ready to trigger.
  ***************************************************************************/

    else if (tact_is_pressed && !long_press_effect_flag)
    {
        long_press_counter++;   // Keep counting, no flag yet
    }
#endif

    /***************************************************************************
  * Mark the pressed button as read to prevent multiple readings
  ***************************************************************************/

    lastOutput = btnOutput; //next time, wont trigger again
}