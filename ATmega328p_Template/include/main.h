#ifndef MAIN_H
#define MAIN_H

#include "app_config.h"
#include <Arduino.h>
#include <SPI.h>

#include "74HC165.h"
#include "tact.h"
#include "tact_functions.h"
#include "FSM_config.h"
#include "menu.h"

#include "Timers.h"
#include "sleep.h"

/*##################################################################
ADDONS : headers included if defined in app_config
##################################################################*/

#if FOUR_LCD_CONFIG
// Add external libraries
#include <LCD.h>
#include <LiquidCrystal_I2C.h> // F Malpartida's NewLiquidCrystal library
// Addon library
#include <4x20_LCD.h>
#endif

#if ST7789_CONFIG
// Add external libraries
#include <Adafruit_ST7789.h>    //includes Adafruit_GFX.h
// Addon library
#include <ST7789_oled.h>
#endif

#endif // MAIN_H