#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <SPI.h> // Arduino SPI library
#include <VL53L1X.h>
#include <Wire.h>

VL53L1X sensor;

#define THRESHOLD 100

#define MASK_MAXIMUM 3
#define UNMASK_MAXIMUM -3

//the curr needs to compare to the SAME last for all iterations. As soon as threshold is busted, keep the same lastSpot
#define PATH_UBSTRUCTED 1
#define PATH_CLEAR 0

int savedReadings[5];
uint8_t currSpot = 0;
uint8_t lastSpot;
bool maybeFlag;
int integrator;
bool tof_status;

void debounceTOF()
{
  savedReadings[currSpot] = sensor.read();
  ;
  if (!maybeFlag)
    lastSpot = currSpot;
  (currSpot < 5) ? (currSpot++) : (currSpot = 0);
  //input = abs(savedReadings[currSpot] - savedReadings[lastSpot]);
  if (savedReadings[lastSpot] - savedReadings[currSpot] > THRESHOLD) //if last was bigger, someone might be in front
  {
    if (integrator < MASK_MAXIMUM)
    {
      integrator++;
      if (!maybeFlag)
        maybeFlag++; //on as long as integ isnt 0
    }
  }
  else if (savedReadings[currSpot] - savedReadings[lastSpot] > THRESHOLD) //if now is bigger, someone left
  {
    if (integrator > UNMASK_MAXIMUM)
    {
      integrator--;
      if (!maybeFlag)
        maybeFlag++;
    }
  }
  else if (integrator > 0 && integrator < MASK_MAXIMUM)
    integrator--;
  else if (integrator < 0 && integrator > UNMASK_MAXIMUM)
    integrator++;

  if (integrator >= MASK_MAXIMUM)
  {
    integrator = 0; // Defensive code if integrator got corrupted
    tof_status = PATH_UBSTRUCTED;
    maybeFlag = 0;
  }

  if (integrator <= UNMASK_MAXIMUM)
  {
    integrator = 0; // Defensive code if integrator got corrupted
    tof_status = PATH_CLEAR;
    maybeFlag = 0;
  }
}

void setup()
{

  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C
  sensor.setTimeout(500);

  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1)
      ;
  }

  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(50000);
  sensor.startContinuous(50);
}

void loop()
{


  debounceTOF();
  if (tof_status)
    Serial.println("blocked");
  else
    Serial.println("clear");
  /*
Serial.print("status: ");
Serial.println(tof_status);

Serial.println(savedReadings[currSpot]);
//Serial.println(savedReadings[lastSpot]);
Serial.print("int: ");
Serial.println(integrator);
//Serial.print("last: ");
//Serial.println(lastSpot);
*/
  delay(200);
}