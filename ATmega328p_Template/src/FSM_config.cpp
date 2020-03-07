#include "FSM.h"

FSM myFSM;

// FSM events must be listed in functions_config.h

/*####################################################################################################
    setup which initial state for the State machine
####################################################################################################*/

void FSM::init()
{
    myFSM.setState(INIT_stateHandler);
    print_init_page();
}

/*####################################################################################################
    create your state handling functions for your FSM here
####################################################################################################*/

/***************************************************************************
 * States:
 * INIT, SETUP, WAIT_FOR_RFID, TOF, 
 * 
 ***************************************************************************/

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
            void print_wait_for_rfid_page();
            myFSM.setState(WAIT_FOR_RFID_stateHandler);
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

void WAIT_FOR_RFID_stateHandler()
{
}