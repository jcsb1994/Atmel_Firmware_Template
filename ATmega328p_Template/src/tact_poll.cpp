#include "tact_poll.h"

/***************************************************************************
 * 
 * variables
 * 
 ***************************************************************************/

volatile int pressed_button_semaphore;

#if LONG_BUTTON_PRESS_CONFIG == 1
volatile int long_press_counter;
volatile int long_press_effect_flag;
#endif

/***************************************************************************
 * 
 *Button polling variables
 * 
 ***************************************************************************/

volatile bool refresh_flag;

/*##################################################
            FUNCTIONS
##################################################*/

void pollButton(int pin)
{

  /***************************************************************************
  * Option 1: The button "pin" was just pressed.
  * If it was LOW and now HIGH (active HIGH), action is activated and
  * refresh flag is set to refresh the screen. The semaphore value is set
  * to the current polled button.
  ***************************************************************************/
#if BUTTON_ACTIVE_STATE_CONFIG == 1
  if (btnOutput[pin] && !lastOutput[pin])
  {
#elif BUTTON_ACTIVE_STATE_CONFIG == 0
  if (!btnOutput[pin] && lastOutput[pin])
  {
#endif

    pressed_button_semaphore = pin; //button being polled is now flagged as pressed

#if SHORT_BUTTON_PRESS_CONFIG == 1
    //add a pressed effect here:
    shortSwitchActions(pin);
    refresh_flag++;
#endif
  }

  /***************************************************************************
  * Option 2: the button "pin" was just released.
  * check if buttons are active HIGH or LOW
  * if release is on, activate effect.
  * If debounced button is now LOW and was HIGH, its released so no long press effect is applied.
  ***************************************************************************/

#if BUTTON_ACTIVE_STATE_CONFIG == 1
  else if (lastOutput[pin] && !btnOutput[pin])
  {
#elif BUTTON_ACTIVE_STATE_CONFIG == 0
  else if (!lastOutput[pin] && btnOutput[pin])
  {
#endif


#if BUTTON_RELEASE_CONFIG == 1
    
    if (pressed_button_semaphore)

#if LONG_BUTTON_PRESS_CONFIG == 1
      if(!long_press_effect_flag) //if long press effect occured, releasing will not trigger another effect
#endif
    //add a release effect here:
          releaseSwitchActions(pin),
          refresh_flag++;

    pressed_button_semaphore = 0;

#endif

#if LONG_BUTTON_PRESS_CONFIG == 1
    //if long press effect occured, clear semaphore to prevent short effect:
    if (long_press_effect_flag)
    {
      long_press_effect_flag = 0;
      pressed_button_semaphore = 0;
    }

#endif
  }




  /***************************************************************************
  * Option 3: Long press effect reached
  * The long_press_counter has reached a treshold time value and we are
  * polling the right button, which is pressed and marked with the semaphore.
  ***************************************************************************/

#if LONG_BUTTON_PRESS_CONFIG == 1
  else if (pressed_button_semaphore == pin && long_press_counter >= ITERATIONS_TO_LONG_PRESS_TRIGGER)
  {

    longSwitchActions(pin);
    refresh_flag++;
    long_press_counter = 0;
    long_press_effect_flag++;
  }

  /***************************************************************************
  * Option 4: counting until long effect. 
  * This condition needs to be after "long effect reached" as it is true
  * even when the long press is ready to trigger.
  ***************************************************************************/

  else if (pressed_button_semaphore == pin && !long_press_effect_flag)
  {
    long_press_counter++;
  }
#endif

  /***************************************************************************
  * Mark the pressed button as read to prevent multiple readings
  ***************************************************************************/

  lastOutput[pin] = btnOutput[pin]; //next time, wont trigger again
}
