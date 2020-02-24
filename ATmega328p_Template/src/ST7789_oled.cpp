#include "app_config.h"
#if ST7789_CONFIG

#include "ST7789_oled.h"

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

/*##################################################
            FUNCTIONS
##################################################*/

void tft_setup() // Put any ST7789 function needed for the setup code
{
    tft.init(240, 240, SPI_MODE2); // Init ST7789 display 240x240 pixel
   tft.setRotation(2);
    tft.fillScreen(ST77XX_BLACK);
    tft.setTextSize(3);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextWrap(true);
    tft.setCursor(0, 2 * SCREEN_TEXT_PIXEL);
    tft.print("Dummie text");
}

#endif