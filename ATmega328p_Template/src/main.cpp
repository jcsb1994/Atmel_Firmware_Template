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


  input_shift_register buttons_shift = {1};
 
  tact upPin(2);
  tact selectPin(0, buttons_shift);

void setup()
{

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
  upPin.setFunctions(up_short, up_release, up_long);
}

void loop()
{
  
  upPin.debounce();
  //upPin.state = upPin.poll;  // change for auto set state. then, switch case for state if (upPin.state)
  upPin.poll(DEBOUNCED); // Changes tact state automatically
  
  if(upPin.state)
      //Serial.println("activated!"),
      Serial.println(upPin.state),
    upPin.activate();
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