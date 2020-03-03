#ifndef LCD_H
#define LCD_H

#include "main.h"

#include <LCD.h>
#include <LiquidCrystal_I2C.h> // F Malpartida's NewLiquidCrystal library

/*##################################################
            MACROS
##################################################*/

//LCD to I2C pinout
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

#define LED_OFF 1 
#define LED_ON 0

/*##################################################
            DECLARATION
##################################################*/

extern LiquidCrystal_I2C lcd;

void lcd_setup();

#endif