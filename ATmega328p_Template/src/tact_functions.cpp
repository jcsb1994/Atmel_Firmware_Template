#include "tact_functions.h"

/* Create functions to link to your tact instances here */

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
        delay(10);
}