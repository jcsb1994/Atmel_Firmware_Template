#include "menu.h"

/*####################################################################################################
    Menu:: config
####################################################################################################*/

//menu instance
menu myMenu(4);

//Set which characters to erase and to print when drawing cursor on screen
#define CURSOR_SIZE 2
void menu::printCursor()
{
    for (int i = 0; i < mRows; i++)
    {
        lcd.setCursor(0, i);
        lcd.print("  ");
    }

    lcd.setCursor(0, menu::cursorPos);
    lcd.print("->");
    Serial.println("arrow");
};

/*####################################################################################################
    Pages to print
####################################################################################################*/

void print_init_page()
{
    lcd.clear();
    lcd.setCursor(CURSOR_SIZE, 0);
    lcd.print("Setup");
    lcd.setCursor(CURSOR_SIZE, 1);
    lcd.print("BT Pairing");
    lcd.setCursor(CURSOR_SIZE, 2);
    lcd.print("Start measuring");
};

void print_setup_page()
{
    lcd.clear();
    lcd.setCursor(CURSOR_SIZE, 0);
    lcd.print("Test dist: ");
};

void print_measuring_page()
{
    lcd.clear();
    lcd.setCursor(CURSOR_SIZE, 0);
    lcd.print("Stop measuring");
    lcd.setCursor(5, 1);
    lcd.print("Waiting for");
    lcd.setCursor(7, 2);
    lcd.print("patients..");
}
