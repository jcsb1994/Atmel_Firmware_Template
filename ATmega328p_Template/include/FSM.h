#ifndef FSM_H
#define FSM_H

#include "main.h"

class FSM
{
public:
    FSM() {}
    enum events
    {
        go_up,
        go_down,
        select
    };

    void getEvent(int incomingEvent)
    {
        incoming_event = incomingEvent;
    }

private:
    int incoming_event;

    void (*do_state)();

    /**********************************************************
     * States in the machine (create an handler for each)
    **********************************************************/

    void STATE_0_handler()
    {
        switch (incoming_event)
        {
        case events::select:
        /*    switch (menu::getCursorPos)
            {
                break;
            
            default:
                break;
            } */
            break;

        default:
            break;
        }
    };
};

#endif