#include "FSM.h"

FSM myFSM;

// FSM events must be listed in functions_config.h

/*####################################################################################################
    setup which initial state for the State machine (and print its page)
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
            myMenu.setCurrentPage(print_setup_page); // Used because refreshPage() is used in this state
            myFSM.setState(SETUP_stateHandler);
            break;

        case INIT_START_POS:
            print_wait_for_rfid_page();
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

    case events::increment:
        switch (myMenu.getCursorPos())
        {
        case SETUP_TEST_TYPE_POS:

            gait_assessment.setTestTypeUp();
            gait_assessment.exactDistance = gait_assessment.getTestType() * 100;
            myMenu.refreshPage();
            break;

        case SETUP_EXACT_DISTANCE:
            gait_assessment.exactDistance++;
            myMenu.refreshPage();
            break;

        default:
            break;
        }
        break;

    case events::decrement:
        switch (myMenu.getCursorPos())
        {
        case SETUP_TEST_TYPE_POS:

            gait_assessment.setTestTypeDown();
            gait_assessment.exactDistance = gait_assessment.getTestType() * 100;
            myMenu.refreshPage();
            break;

        case SETUP_EXACT_DISTANCE:
            gait_assessment.exactDistance--;
            myMenu.refreshPage();
            break;

        default:
            break;
        }
        break;

    case events::select:
        if (myMenu.getCursorPos() == SETUP_BT_PAIR_POS)
            //go to BT menu
            //void print_wait_for_rfid_page();
            //myFSM.setState(WAIT_FOR_RFID_stateHandler);
            break;
        break;

    default:
        break;
    }
}

void WAIT_FOR_RFID_stateHandler()
{
    switch (myFSM.getEvent())
    {
    case events::back:
        print_init_page();
        myFSM.setState(INIT_stateHandler);
        break;

    case events::RFID_detected:
        print_rfid_detected_page();
        myFSM.setState(TOF_stateHandler);
        break;

    case events::select: // Pressing select gets you into continuous reading
        myFSM.setEvent(events::RFID_detected);
        break;

    default:
        break;
    }
}

void TOF_stateHandler()
{
    //   if(!mySensor.flag)
    mySensor.debounce();    // Read TOF sensor
    finalSensor.debounce(); // Read 2nd
    // If we flag, do not debounce the flagged sensor
    // the 1st flag sets start time, the second is ending time.
  if (mySensor.getStatus())
    Serial.println("blocked");
  if (finalSensor.getStatus())
    Serial.println("blocked too!");
/*
    if (mySensor.getStatus() && !mySensor.flag)
        mySensor.flag++;
    if (finalSensor.getStatus() && !finalSensor.flag)
        finalSensor.flag++;
    if (!mySensor.getStatus() && mySensor.flag) //then if flag is up, and status is back to 0, save time

        if (gait_assessment.hasBegun())
        {
        }
*/
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
