#include "app_config.h"


input_shift_register buttons_shift;

tact upPin(2);
tact selectPin(0, buttons_shift);




ISR(WDT_vect)
{
  upPin.timerCount();
  selectPin.timerCount();
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
  pinMode(timerLedPin, OUTPUT);

  upPin.setFunctions(up_short, up_release, up_long);
  selectPin.setFunctions(s_short, s_release, s_long);

  input_shift_reg_SPI_init();
  WDT_setup();
  //timer1_setup();
  sleep_setup();
  
  //tft_setup();
  lcd_setup();

}

void loop()
{

  shift_reg_snapshot();
  buttons_shift.data = transfer_shift_reg_data();  

  upPin.poll(NOT_DEBOUNCED);  // Do not debounce if using sleep!
  selectPin.poll(NOT_DEBOUNCED);

  upPin.activate();
  selectPin.activate();


 //activate_sleep();
 
}
