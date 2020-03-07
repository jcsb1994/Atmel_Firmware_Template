#ifndef TACT_ACT_H
#define TACT_ACT_H

#include "main.h"

/*####################################################################################################
    Tact switch buttons actions (create a function for each) **in tact config cpp file
####################################################################################################*/

void empty();

void up_short();

void up_release();

void up_long();

void s_short();

void s_release();

void s_long();

void t_short();

void t_release();

void t_long();

// Left button
void left_s();

void left_r();

/*####################################################################################################
    Pages to print (create a function for each) **in menu config cpp file
####################################################################################################*/

#define INIT_SETUP_POS 0
#define INIT_BT_PAIR_POS 1
#define INIT_START_POS 2
void print_init_page();


void print_wait_for_rfid_page();

void print_setup_page();

/*####################################################################################################
    State Machine (FSM) events (list all possible events here)
####################################################################################################*/
enum events
{
    increment,
    decrement,
    select,
    RFID_detected,
    back,
    tof_detected,

};

/*####################################################################################################
    State Machine (FSM) state handlers (create a function for each) **in FSM config cpp file
####################################################################################################*/

void INIT_stateHandler();

void SETUP_stateHandler();

void BT_PAIR_stateHandler();

void WAIT_FOR_RFID_stateHandler();

#endif