#ifndef ST_OLED_H
#define ST_OLED_H

#if ST7789_CONFIG

#include "app_config.h"
#include <Adafruit_ST7789.h>    //includes Adafruit_GFX.h

extern Adafruit_ST7789 tft;

/*##################################################
            FUNCTIONS
##################################################*/

void tft_setup();

#endif
#endif