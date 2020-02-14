#include <tact.h>

void input_shift_reg_SPI_init()
{
    pinMode(loadPin, OUTPUT);
    SPI.setClockDivider(SPI_CLOCK_DIV128);
    SPI.setDataMode(SPI_MODE0);
    SPI.setBitOrder(MSBFIRST);
    SPI.begin();
}

void shift_reg_snapshot()
{
    PORTD &= ~(1 << loadPin);
    delay(1);
    PORTD ^= (1 << loadPin);
}

int transfer_shift_reg_data()
{
    int data = SPI.transfer(0x00);
    return data;
}

tact::tact(int assigned_pin)
{

    pin = assigned_pin; // Associate the pin to the private pin in the class

#if BUTTON_ACTIVE_STATE_CONFIG == 1
    pinMode(pin, INPUT);
#elif BUTTON_ACTIVE_STATE_CONFIG == 0
    pinMode(pin, INPUT_PULLUP);
#endif
}

tact::tact(int assigned_pin, input_shift_register &shift)
{
    pin = assigned_pin; // Associate the pin to the private pin in the class
    input_shift_used++;
    tact::input_shift_ptr = &shift;
}

void tact::debounce()
{
    if (input_shift_used)
    {
        input = (input_shift_ptr->data & (1 << pin)) >> pin;
    }
    else
        input = digitalRead(pin);

    if (input == 0)
    {
        if (integrator > 0)
            integrator--;
    }
    else if (integrator < MAXIMUM)
        integrator++;

    if (integrator == 0)
        btnOutput = 0;
    else if (integrator >= MAXIMUM)
    {
        integrator = MAXIMUM; // Defensive code if integrator got corrupted
        btnOutput = 1;
    }
}

short tact::poll(bool debounce_flag) //accepts DEBOUNCED or NOT_DEBOUNCED
{

    if (debounce_flag == NOT_DEBOUNCED)
    {
        if (!input_shift_used)
            btnOutput = digitalRead(tact::pin);
        else
            btnOutput = ((input_shift_ptr->data & (1 << pin)) >> pin);
    }

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
        tact_is_pressed++;

#if !TACT_TIMER_INTERRUPT_CONFIG
        last_press_millis = millis();
        Serial.println(last_press_millis);
#endif

#if SHORT_BUTTON_PRESS_CONFIG == 1
        tact::state = SHORT_EFFECT_REQUIRED;
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

#if BUTTON_RELEASE_CONFIG

        if (tact_is_pressed)
        {

#if LONG_BUTTON_PRESS_CONFIG == 1 && !RELEASE_AFTER_LONG_EFFECT_CONFIG
            if (!long_effect_done) //if there was no long press. If there was, releasing will not trigger another effect
#endif
                tact::state = RELEASE_EFFECT_REQUIRED;
        }
#endif

#if LONG_BUTTON_PRESS_CONFIG == 1
        long_effect_done = 0;
        long_press_counter = 0;
#endif

        tact_is_pressed = 0;
    }

    /***************************************************************************
  * Option 3: Long press effect reached
  * (either counted in the timer with tact.timerCount) or with millis())
  * 
  * The long_press_counter has reached a treshold time value and we are
  * polling the right button, which is pressed and marked with the semaphore.
  ***************************************************************************/

#if LONG_BUTTON_PRESS_CONFIG == 1

#if TACT_TIMER_INTERRUPT_CONFIG
    else if (tact_is_pressed && !long_effect_done && long_press_counter >= ITERATIONS_TO_LONG_PRESS_TRIGGER)
    {
        //Serial.println(long_press_counter);
        long_press_counter = 0; // Stop counting, flag up
#else
    else if (tact_is_pressed && !long_effect_done && (millis() - last_press_millis) >= LONG_PRESS_DELAY)
    {
#endif
#endif
        tact::state = LONG_EFFECT_REQUIRED;
        long_effect_done++;
    }

    /***************************************************************************
  * Mark the pressed button as read to prevent multiple readings
  ***************************************************************************/

    lastOutput = btnOutput;
    return tact::state;
}

void tact::setFunctions(void short_press_function(), void release_press_function(), void long_press_function())
{
    short_ptr = short_press_function;
    release_ptr = release_press_function;
    long_ptr = long_press_function;
}

void tact::activate()
{
    if (state)
    {
        switch (tact::state)
        {
        case SHORT_EFFECT_REQUIRED:
            short_ptr();
            break;

        case RELEASE_EFFECT_REQUIRED:
            release_ptr();
            break;

        case LONG_EFFECT_REQUIRED:
            long_ptr();
            break;

        default:
            break;
        }
        tact::state = 0;
    }
}

void tact::timerCount()
{
    if (tact_is_pressed && !long_effect_done)
        long_press_counter++;
}