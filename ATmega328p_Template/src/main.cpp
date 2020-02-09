#include "app_config.h"
#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  tact upPin(2);
  upPin.debounce();
  interface[] = upPin.poll();




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