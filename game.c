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
#include "choice.h"
#include "result.h"

#define PACER_RATE 500

static const char* player_options[] =
{
	"  ROCK", "  FIRE", "  SCISSORS", "  HUMAN", "  WOLF",
	"  SPONGE", "  PAPER", "  AIR", "  WATER", "  DEVIL", "  GUN"
};
	

int main(void) {
    init_game();
    start_game();
    int score = 0;
    int opp_score = 0;
	int player_choice = 0;
	int previous_choice = player_choice;
    tinygl_text(player_options[player_choice]);
	bool receive_state = false;

	while (1) {
        if (!receive_state) {
            if (previous_choice != player_choice) {
                tinygl_text(player_options[player_choice]);
                previous_choice = player_choice;
            }
            pacer_wait();
            tinygl_update();
            navswitch_update();
            if (navswitch_push_event_p(NAVSWITCH_WEST)) {
                player_choice++;
                if (player_choice > 10) {
                    player_choice = 0;
                }
            } else if (navswitch_push_event_p(NAVSWITCH_EAST)) {
                player_choice--;
                if (player_choice < 0) {
                    player_choice = 10;
                }
            }
			if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
				send_choice(player_choice);
				receive_state = true;
			}
            if (ir_uart_read_ready_p()) {	
				char ch = ir_uart_getc();
				if ((ch >= 65) & (ch <= 75)) {
					int opp_choice = convert_recieved(ch);
					char result = check_result(player_choice, opp_choice);
                    if (result == 'w') {
                        score++;
                    } else if (result == 'l') {
                        opp_score++;
                    }
					ir_uart_putc(result);
					display_result(result);
                    display_score(score);
					previous_choice = -1;
                    if ((score == 3) | (opp_score == 3)) {
                        break;
                    }
				}
			}
		} else {
			if (ir_uart_read_ready_p()) {	
				char ch = ir_uart_getc();
				if ((ch == 'l') | (ch == 'd') | (ch == 'w')) {
					char result = received_result(ch);
                    if (result == 'w') {
                        score++;
                    } else if (result == 'l') {
                        opp_score++;
                    }
					display_result(result);
                    display_score(score);
					receive_state = false;
					previous_choice = -1;
                    if ((score == 3) | (opp_score == 3)) {
                        break;
                    }
			    }
			}
	    }
    }
    if (score == 3) {
        tinygl_text("  CONGRATS, YOU WON!");
    } else {
        tinygl_text("  HARD LUCK, YOU LOST");
    }

    int counter = 0;
	while (counter < 5000) {
	    pacer_wait();
	    tinygl_update();
	    counter++;
	}
}		
