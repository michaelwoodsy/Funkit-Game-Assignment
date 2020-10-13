/** @file   game_setup.h
    @author Michael Woodard and Sean Lalor
    @date   10 Oct 2020
    @brief  This is the interface used to initialise and start the game.
*/

#ifndef GAME_SETUP_H
#define GAME_SETUP_H

#include "system.h"
#include "tinygl.h"
#include "navswitch.h"
#include "pacer.h"
#include "ir_uart.h"
#include "text_output.h"

#define PACER_RATE 500 /* Sets the pacer. */

/* Initialises the system, infra-red receiver and the pacer.
   It also calls the function to present the welcoming text
   to the player. */
void init_game(void);

/* Waits for the player to press down on the navswitch. Once
   the navswitch is pressed, the game starts. */
void start_game(void);

#endif
