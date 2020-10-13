/** @file   game_setup.c
    @author Michael Woodard and Sean Lalor
    @date   10 Oct 2020
    @brief  This is used to initialise and start the game.
*/


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
void init_game(void) {
	system_init();
	ir_uart_init();
	intro_text();
	pacer_init(PACER_RATE);
}

/* Waits for the player to press down on the navswitch. Once
   the navswitch is pressed, the game starts. */
void start_game(void) {
	while (1) {
		pacer_wait();
		tinygl_update();
		navswitch_update();
		if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
			break;
		}
	}
}
