/** @file   result.c
    @author Michael Woodard and Sean Lalor
    @date   10 Oct 2020
    @brief  This is used to compare the two player's
            options to determine a winner.
*/


#include "system.h"

/* Compares the player's choice with his/her opponents choice
   to determine a winner. Each int corresponds to a certain 
   option, which can be seen in the player_options struct in
   game.c. Explanation on which options win/lose to other options
   is in the README. A character 'w', 'd', or 'l is returned 
   corresponding to a win, draw or loss. */
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

/* Converts the opponents win/loss to a loss/win.
   If this was not done both player's would think
   they have won/lost. */
char received_result(char result) {
	if (result == 'd') {
		return 'd';
	} else if (result == 'l') {
		return 'w';
	} else {
		return 'l';
	}
}
