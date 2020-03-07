#include "app_functions.h"

/* Create functions to link to your tact instances here */

// Up button

void up_short()
{
  myMenu.moveCursor(DOWN);

  digitalWrite(ledPin, HIGH);
}
void up_release()
{
  digitalWrite(ledPin, LOW);
}

void up_long()
{
}

// Select Button

void s_short()
{
  digitalWrite(LedPin2, HIGH);
  myFSM.setEvent(events::select);
}
void s_release()
{
  digitalWrite(LedPin2, LOW);
}
void s_long()
{
}

// Down button

void t_short()
{
  digitalWrite(LedPin3, HIGH);
  myMenu.moveCursor(UP);
}
void t_release()
{
  digitalWrite(LedPin3, LOW);
}
void t_long()
{
}

// Left Button

void left_s()
{
  myFSM.setEvent(events::back);
}

void left_r()
{

}