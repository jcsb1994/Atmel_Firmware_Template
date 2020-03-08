#include "functions_config.h"

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

void down_s()
{
  digitalWrite(LedPin3, HIGH);
  myMenu.moveCursor(UP);
}
void down_r()
{
  digitalWrite(LedPin3, LOW);
}
void down_h()
{
}

// Left Button

void left_s()
{
  digitalWrite(LedPin3, HIGH);
  myFSM.setEvent(events::back);
}

void left_r()
{
digitalWrite(LedPin3, LOW);
}