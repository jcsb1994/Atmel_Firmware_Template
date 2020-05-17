#ifndef FSM_H
#define FSM_H

#include "tact.h"
#include "menu.h"
#include "main.h"


class FSM
{

private:
    int incoming_event;

    void (*do_state)();

    menu *myMenu;
    tact *myButtons;

public:
    FSM()
    {
        myMenu = new menu(UI_MENU_ROW_NB);
        myButtons = new tact[buttons_names::TOTAL_NUMBER_OF_BUTTONS];
        for (int i; i < TOTAL_NUMBER_OF_BUTTONS; i++)
        {
            myButtons[i].setPin(used_tact_pins[i]);
        }
    }

    ~FSM()
    {
        delete myMenu;
    }

    struct states;

    //enum events;
    //enum events : unsigned int;

    menu *getMenu()
    {
        return myMenu;
    }

    tact getTact(int target_tact)
    {
        return (myButtons[target_tact]);
    }



    int getEvent() //used as output for tact switches
    {
        //if(incoming_event)Serial.print("ev "), Serial.println(incoming_event);
        int event = incoming_event;
        incoming_event = 0;
        return event;
    }

    void setEvent(int incomingEvent) //used as output for tact switches
    {
        incoming_event = incomingEvent;
    }

    void setState(void newStateHandler())
    {
        do_state = newStateHandler;
    }

    void doState()
    {
        do_state();
    }

    void init();
};

extern FSM myFSM;

#endif