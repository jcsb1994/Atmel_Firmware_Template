#include "FSM.h"

FSM myFSM;

/*####################################################################################################
    List all events in your FSM here
####################################################################################################*/

void FSM::init()
{
    myFSM.setState(INIT_stateHandler);
    print_init_page();
}

/*####################################################################################################
    create your state handling functions for your FSM here
####################################################################################################*/

void INIT_stateHandler()
{
    if (myFSM.getEvent() == events::select)
    {
        switch (myMenu.getCursorPos())
        {
        case INIT_SETUP_POS:
            print_setup_page();
            myFSM.setState(SETUP_stateHandler);
            break;

        case INIT_BT_PAIR_POS:
            break;

        case INIT_START_POS:
            void print_measuring_page();
            myFSM.setState(MEASURING_stateHandler);
            break;

        default:
            break;
        }
    }
}

void SETUP_stateHandler()
{
    switch (myFSM.getEvent())
    {
    case events::back:
        print_init_page();
        myFSM.setState(INIT_stateHandler);
        break;

    default:
        break;
    }
}

void MEASURING_stateHandler()
{
}