#include "app_config.h"
#include <Arduino.h>

#define ledPin 7

void up_short()
{
  digitalWrite(ledPin, HIGH);
}
void up_release()
{
  digitalWrite(ledPin, LOW);
}
void up_long()
{
  for (int i = 0; i < 6; i++)
    DDRD ^= (1 << ledPin),
        delay(100);
}

void s_short()
{
  digitalWrite(ledPin, HIGH);
}
void s_release()
{
  digitalWrite(ledPin, LOW);
}
void s_long()
{
  for (int i = 0; i < 6; i++)
    DDRD ^= (1 << ledPin),
        delay(100);
}

/*
corriger: tact debounce et poll les d/buts qui traitent le struct ne sont pas bons pcq le struct est mal passe en argument.. 
*/
input_shift_register buttons_shift;
input_shift_register *ptr = &buttons_shift;

tact upPin(2);
tact selectPin(0, buttons_shift);

ISR(WDT_vect)
{
  upPin.timerCount();
  selectPin.timerCount();
}

void setup()
{

  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);

  upPin.setFunctions(up_short, up_release, up_long);
  selectPin.setFunctions(s_short, s_release, s_long);

  input_shift_reg_SPI_init();
  WDT_setup();
  sleep_setup();
}

void loop()
{

  shift_reg_snapshot();

  buttons_shift.data = transfer_shift_reg_data();

  upPin.debounce();
  selectPin.debounce();

  upPin.poll(DEBOUNCED); 
  selectPin.poll(DEBOUNCED);

  upPin.activate();
  selectPin.activate();

  activate_sleep();
}
