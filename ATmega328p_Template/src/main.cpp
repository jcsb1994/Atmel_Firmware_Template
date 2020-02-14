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
input_shift_register buttons_shift = {1};
input_shift_register *ptr = &buttons_shift;

tact upPin(2, *ptr);
tact selectPin(0, *ptr);



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

}

void loop()
{


shift_reg_snapshot();
//Serial.println(8880+buttons_shift.data);

buttons_shift.data = transfer_shift_reg_data();
Serial.print("mains: ");
Serial.println(buttons_shift.data);

  upPin.debounce();
  selectPin.debounce();
  //upPin.state = upPin.poll;  // change for auto set state. then, switch case for state if (upPin.state)
  upPin.poll(DEBOUNCED); // Changes tact state automatically
  selectPin.poll(DEBOUNCED);

  
    upPin.activate();
    selectPin.activate();

}
/*
Below should be changed: place the switch in a separate member that points to tact effect functions
*/

/* how to create a class that creates custom functions for every object created?
I have a class named tact that operates mechanical buttons for embedded applications
I need different interface fonctions to be created for each tact obect created.
For example, if I created a power button, I would generate a function for operating long presses
for this button, which would shut it down, and another for short presses, which would reset it for example
How could I create such a function generating behaviour for my class? That means that if I decided to
create another object, like a enter button, two other functions would be created. I do not want to put them
in the class directly since those functions would be differnt for every button object of course. Any Idea 
how I could do this? thanks!
*/