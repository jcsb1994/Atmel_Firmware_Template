#include "main.h"

input_shift_register buttons_shift;

tact *upPin;
tact *downPin;


//tact selectPin(0, buttons_shift);

ISR(WDT_vect)
{
  //upPin.timerCount();
  //downPin.timerCount();
  //selectPin.timerCount();
  tact::timerCount(); // Very important to use this version when not using simultaneous presses (changes long press period)
}

/*
//example use of timer 1
ISR(TIMER1_COMPA_vect)
{
  TCNT1 = 0;
  PORTD ^= (1 << timerLedPin);
  selectPin.debounce(); // Debounce is useful when not sleeping (i.e. when an timer ISR can handle it)
}
*/

ISR(TIMER1_COMPA_vect)
{
  TCNT1 = 0;
  PORTD ^= (1 << timerLedPin);
  //selectPin.debounce(); // Debounce is useful when not sleeping (i.e. when an timer ISR can handle it)
}

void setup()
{
  upPin = new tact(2);
  downPin = new tact(3);

  Serial.begin(9600);
  delay(2000);
  pinMode(ledPin, OUTPUT);
  pinMode(timerLedPin, OUTPUT);

  upPin->setFunctions(up_short, up_release, up_long);
  downPin->setFunctions(s_short, s_release, s_long);
  //selectPin.setFunctions(s_short, s_release, s_long);

  input_shift_reg_SPI_setup();
  WDT_setup();
<<<<<<< HEAD
  //timer1_setup();
  sleep_setup();

  //tft_setup();
  //lcd_setup();
=======
>>>>>>> parent of b02994b... usable but setFunctions needs 3 arguments
}

void loop()
{

  shift_reg_snapshot();
  buttons_shift.data = transfer_shift_reg_data();

  upPin->debounce();
  downPin->debounce();

  upPin->poll(DEBOUNCED); // Do not debounce if using sleep!
  downPin->poll(DEBOUNCED);
  //selectPin.poll(NOT_DEBOUNCED);

  upPin->activate();
  downPin->activate();
 // selectPin.activate();

<<<<<<< HEAD
  //activate_sleep();
=======
>>>>>>> parent of b02994b... usable but setFunctions needs 3 arguments
}
