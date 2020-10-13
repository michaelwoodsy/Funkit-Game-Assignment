/** @file   game.c
    @author Michael Woodard and Sean Lalor
    @date   7 Oct 2020
    @note   does nothing
*/
#ifndef GAME_SETUP_H
#define GAME_SETUP_H

#include "system.h"
#include "tinygl.h"
#include "navswitch.h"
#include "pacer.h"
#include "ir_uart.h"
#include "pio.h"
#include "../fonts/font3x5_1.h"

#define PACER_RATE 500

void init_game(void);

void start_game(void);

#endif
