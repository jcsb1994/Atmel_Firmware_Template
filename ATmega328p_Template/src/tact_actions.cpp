#include "tact_actions.h"

/*##################################################
            FUNCTIONS
##################################################*/

#if BUTTON_RELEASE_CONFIG == 1

void releaseSwitchActions(int pin)
{
  switch (pin)
  {
  case upPin:
    switch (menuState)
    {
    case CLOCK_MENU:

      break;
    case DATE_MENU:
      alarmTime++;
      break;
    case HEART_MENU:
      cursorPos -= SCREEN_TEXT_PIXEL;
      break;
    default:
      break;
    }
    break;
  case downPin:
    switch (menuState)
    {
    case CLOCK_MENU:

      break;
    case DATE_MENU:
      alarmTime--;
      break;
    case HEART_MENU:
      cursorPos += SCREEN_TEXT_PIXEL;
      break;
    default:
      break;
    }
    break;

  default:
    break;
  }
}

#endif

#if SHORT_BUTTON_PRESS_CONFIG == 1

void shortSwitchActions(int pin)
{
}

#endif

#if LONG_BUTTON_PRESS_CONFIG == 1

void longSwitchActions(int pin)
{
  switch (pin)
  {
  case upPin:
    if (menuState != LAST_MENU_PAGE)
      menuState++;
    else
      menuState = 0;
    break;
    
  case downPin:
    if (menuState != 0)
      menuState--;
    else
      menuState = LAST_MENU_PAGE;
    break;

  default:
    break;
  }
}

#endif