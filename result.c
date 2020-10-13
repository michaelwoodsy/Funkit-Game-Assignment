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
#include "game_setup.h"

#define PACER_RATE 500

char check_result(int player_choice, int opponent_choice) {
    int oc = opponent_choice;
	if (player_choice == oc) {
		return 'd';
	} else if (player_choice == 0) {
		if ((oc == 1) | (oc == 2) | (oc == 3) | (oc == 4) | (oc == 5)) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 1) {
		if ((oc == 2) | (oc == 3) | (oc == 4) | (oc == 5) | (oc == 6)) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 2) {
		if ((oc == 3) | (oc == 4) | (oc == 5) | (oc == 6) | (oc == 7)) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 3) {
		if ((oc == 4) | (oc == 5) | (oc == 6) | (oc == 7) | (oc == 8)) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 4) {
		if ((oc == 5) | (oc == 6) | (oc == 7) | (oc == 8) | (oc == 9)) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 5) {
		if ((oc == 6) | (oc == 7) | (oc == 8) | (oc == 9) | (oc == 10)) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 6) {
		if ((oc == 7) | (oc == 8) | (oc == 9) | (oc == 10) | (oc == 0)) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 7) {
		if ((oc == 8) | (oc == 9) | (oc == 10) | (oc == 0) | (oc == 1)) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 8) {
		if ((oc == 9) | (oc == 10) | (oc == 0) | (oc == 1) | (oc == 2)) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 9) {
		if ((oc == 10) | (oc == 0) | (oc == 1) | (oc == 2) | (oc == 3)) {
			return 'w';
		} else {
			return 'l';
		}
	} else {
		if ((oc == 0) | (oc == 1) | (oc == 2) | (oc == 3) | (oc == 4)) {
			return 'w';
		} else {
			return 'l';
		}
	}
}

char received_result(char result) {
	if (result == 'd') {
		return 'd';
	} else if (result == 'l') {
		return 'w';
	} else {
		return 'l';
	}
}
