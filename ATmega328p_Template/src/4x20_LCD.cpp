#include "4x20_LCD.h"

#if FOUR_LCD_CONFIG
LiquidCrystal_I2C lcd(LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

void lcd_setup() {
  lcd.begin(20, 4); // initialize the lcd
  //lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(LED_OFF);  //turn on backlight
  lcd.backlight(); //Backlight ON if under program control
  lcd.setCursor(0, 0); //character 1 on line 0
  lcd.print("Dummie code");
}

#endif
