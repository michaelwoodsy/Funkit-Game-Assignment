/** @file   game.c
    @author Michael Woodard and Sean Lalor
    @date   7 Oct 2020
    @note   does nothing
*/

#include "system.h"
#include "tinygl.h"
#include "navswitch.h"
#include "pacer.h"
#include "ir_uart.h"
#include "pio.h"
#include "../fonts/font3x5_1.h"
#include "text_output.h"

#define PACER_RATE 500

void init_game(void) {
	system_init();
	ir_uart_init();
	intro_text();
	pacer_init(PACER_RATE);
}

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
