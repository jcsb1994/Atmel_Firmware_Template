#include "tact_functions.h"

/* Create functions to link to your tact instances here */

void up_short()
{
  digitalWrite(ledPin, HIGH);
}
void up_release()
{
  digitalWrite(ledPin, LOW);
  Serial.println("release effect");
}

void up_long()
{
  Serial.println("MARCHE");
  for (int i = 0; i < 6; i++)
    DDRD ^= (1 << ledPin),
        delay(100);
}

void s_short()
{
  digitalWrite(timerLedPin, HIGH);
  Serial.println("lol");
}
void s_release()
{
  digitalWrite(timerLedPin, LOW);
  Serial.println("fu");
}
void s_long()
{
  Serial.println("MARCHE PAS");
digitalWrite(timerLedPin, HIGH);
delay(100);
digitalWrite(timerLedPin, LOW);
delay(100);
digitalWrite(timerLedPin, HIGH);
delay(100);
digitalWrite(timerLedPin, LOW);
}