#include "main.h"


menu myMenu(4);

input_shift_register buttons_shift;

tact upPin(3);
tact selectPin(4);
tact downPin(5);

ISR(WDT_vect)
{
  //upPin.timerCount();
  //selectPin.timerCount();
  //tact::timerCount(); // Very important to use this version when not using simultaneous presses (changes long press period)
  //Serial.println((int)&selectPin.long_ptr, HEX);
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



void setup()
{
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(LedPin2, OUTPUT);
  pinMode(LedPin3, OUTPUT);

  upPin.setFunctions(up_short, up_release, up_long);
  selectPin.setFunctions(s_short, s_release, s_long);
  downPin.setFunctions(t_short, t_release, t_long);

  input_shift_reg_SPI_setup();
  WDT_setup();

  //timer1_setup();
  sleep_setup();
  //tft_setup();
  //lcd_setup();
}

void loop()
{
  //myMenu.setCursor(UP);

  shift_reg_snapshot();
  buttons_shift.data = transfer_shift_reg_data();

  upPin.poll(NOT_DEBOUNCED); // Do not debounce if using sleep!
  selectPin.poll(NOT_DEBOUNCED);
  downPin.poll(NOT_DEBOUNCED);

  upPin.activate();
  selectPin.activate();
  downPin.activate();

  //activate_sleep();
}
