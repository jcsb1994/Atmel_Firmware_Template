#include "DS1307.h"

RTC_DS1307 REAL_TIME_CLOCK_NAME_CONFIG;

/*##################################################
            FUNCTIONS
##################################################*/

void DS1307_setup()
{
  REAL_TIME_CLOCK_NAME_CONFIG.begin();
  REAL_TIME_CLOCK_NAME_CONFIG.adjust(DateTime(__DATE__, __TIME__));
  //REAL_TIME_CLOCK_NAME_CONFIG.adjust(DateTime(2016, 11, 19, 13, 45, 0)); // <----------------------SET TIME AND DATE: YYYY,MM,DD,HH,MM,SS
}

