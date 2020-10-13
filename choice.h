/** @file   game.c
    @author Michael Woodard and Sean Lalor
    @date   7 Oct 2020
    @note   does nothing
*/
#ifndef CHOICE_H
#define CHOICE_H

#include "system.h"
#include "tinygl.h"
#include "navswitch.h"
#include "pacer.h"
#include "ir_uart.h"
#include "pio.h"
#include "../fonts/font3x5_1.h"

#define PACER_RATE 500

void send_choice(int player_choice);

int convert_recieved(char ch);

#endif
