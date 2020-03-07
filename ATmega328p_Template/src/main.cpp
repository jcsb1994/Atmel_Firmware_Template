#include "main.h"

input_shift_register buttons_shift;

tact upPin(4);
tact selectPin(3);
tact downPin(5);
tact leftPin(6);



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

  upPin.setFunctions(up_short, up_release);
  selectPin.setFunctions(s_short, s_release);
  downPin.setFunctions(t_short, t_release);
  leftPin.setFunctions(left_s, left_r);

  input_shift_reg_SPI_setup();
  WDT_setup();
  //timer1_setup();
  sleep_setup();

  lcd_setup();
  myFSM.init();
}

void loop()
{
  myFSM.doState();
  
  shift_reg_snapshot();
  buttons_shift.data = transfer_shift_reg_data();

  upPin.poll(NOT_DEBOUNCED); // Do not debounce if using sleep!
  selectPin.poll(NOT_DEBOUNCED);
  downPin.poll(NOT_DEBOUNCED);
  leftPin.poll(NOT_DEBOUNCED);

  upPin.activate();
  selectPin.activate();
  downPin.activate();
  leftPin.activate();

  //activate_sleep();
}
