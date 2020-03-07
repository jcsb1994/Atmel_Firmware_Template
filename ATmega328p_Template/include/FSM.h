#ifndef FSM_H
#define FSM_H

#include "main.h"

class FSM
{

private:
    int incoming_event;

    void (*do_state)();

public:
    FSM() {}

    enum events : unsigned int;

    int getEvent() //used as output for tact switches
    {
        return incoming_event;
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