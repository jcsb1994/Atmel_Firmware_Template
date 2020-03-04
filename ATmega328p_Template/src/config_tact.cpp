#include "tact_functions.h"

/* Create functions to link to your tact instances here */

void empty() {}

void up_short()
{
  //menu::setCursor(UP);

  digitalWrite(ledPin, HIGH);
  Serial.println("short");
  delay(50);
  digitalWrite(ledPin, LOW);
  delay(50);
  digitalWrite(ledPin, HIGH);
}
void up_release()
{
  digitalWrite(ledPin, LOW);
}
void up_long()
{
  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(ledPin, LOW);
  delay(50);
  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(ledPin, LOW);
  delay(50);
  digitalWrite(ledPin, LOW);
  delay(50);
  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(ledPin, LOW);
}

void s_short()
{
  digitalWrite(LedPin2, HIGH);
}
void s_release()
{
  digitalWrite(LedPin2, LOW);
}
void s_long()
{
  digitalWrite(LedPin2, HIGH);
  delay(50);
  digitalWrite(LedPin2, LOW);
  delay(50);
  digitalWrite(LedPin2, HIGH);
  delay(50);
  digitalWrite(LedPin2, LOW);
  delay(50);
  digitalWrite(LedPin2, HIGH);
  delay(50);
  digitalWrite(LedPin2, LOW);
  delay(50);
  digitalWrite(LedPin2, HIGH);
  delay(50);
  digitalWrite(LedPin2, LOW);
  delay(50);
  digitalWrite(LedPin2, HIGH);
}

void t_short()
{
  digitalWrite(LedPin3, HIGH);
}
void t_release()
{
  digitalWrite(LedPin3, LOW);
}
void t_long()
{
  digitalWrite(LedPin3, HIGH);
  delay(50);
  digitalWrite(LedPin3, LOW);
  delay(50);
  digitalWrite(LedPin3, HIGH);
  delay(50);
  digitalWrite(LedPin3, LOW);
}