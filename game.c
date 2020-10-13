/** @file   game.c
    @author Michael Woodard and Sean Lalor
    @date   7 Oct 2020
    @brief  Is the main module which implements 
            Rock Paper Scissors 11.
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

/* Contains all the possible options a player can select,
   indexed from 0 to 10, and in other functions is 
   indexed from 'A' to 'K' when sending the option over
   to the other funkit. */
static const char* player_options[] =
{
	"  ROCK", "  FIRE", "  SCISSORS", "  HUMAN", "  WOLF",
	"  SPONGE", "  PAPER", "  AIR", "  WATER", "  DEVIL", "  GUN"
};
	
/* Main function which calls on functions in other modules
   to implement the game. User enters a welcoming screen, and 
   once passed this, can select an option in which they would like
   to use. This is sent to the other player's funkit, or the other player's 
   option is received and the player's options are compared to
   determine a winner. The game is played as first to 3 and once
   a player reaches 3 points, an end screen is shown and the game
   restarts from the beginning. Further explanation of Rock Paper
   Scissors 11 can be found in the README. */
int main(void) {
    init_game();
    start_game();
    int score = 0, opp_score = 0, player_choice = 0, previous_choice = player_choice; /* Inititalises both player's scores to 0. */
    tinygl_text(player_options[player_choice]);
	bool receive_state = false; /* Sets player's funkit to not be in a receiving state */

	while (1) {
        if (!receive_state) {
            if (previous_choice != player_choice) {
                tinygl_text(player_options[player_choice]);
                previous_choice = player_choice;
            }

            pacer_wait();
            tinygl_update();
            navswitch_update();
            
            /* Updates option on screen if navswitch is pushed up or down (east/west) */
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

            /* Sends option to other player and sets funkit into a receiving state. */
			if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
				send_choice(player_choice);
				receive_state = true;
			}

            /* Receives other player's option and determines the winner. */
            if (ir_uart_read_ready_p()) {	
				char received_char = ir_uart_getc();
				if ((received_char >= 65) & (received_char <= 75)) {
					int opp_choice = convert_recieved(received_char);
					char result = check_result(player_choice, opp_choice);
                    if (result == 'w') {
                        score++;
                    } else if (result == 'l') {
                        opp_score++;
                    }
                    
                    /* Sends result to other player and displays output of the result on screen. */
					ir_uart_putc(result);
					display_result(result);
                    display_score(score);
					previous_choice = -1;

                    /* Breaks loop and ends game if either player's score has reached 3. */
                    if ((score == 3) | (opp_score == 3)) {
                        break;
                    }
				}
			}
		} else {
            /* Player is in receiving state and waits to find out whether he/she won or not. */
			if (ir_uart_read_ready_p()) {	
				char received_char = ir_uart_getc();
				if ((received_char == 'l') | (received_char == 'd') | (received_char == 'w')) {
					char result = received_result(received_char);
                    if (result == 'w') {
                        score++;
                    } else if (result == 'l') {
                        opp_score++;
                    }

                    /* Displays output of result on screen. */
					display_result(result);
                    display_score(score);
					receive_state = false;
					previous_choice = -1;

                    /* Breaks loop and ends game if either player's score has reached 3. */
                    if ((score == 3) | (opp_score == 3)) {
                        break;
                    }
			    }
			}
	    }
    }
    /* Displays end game text depending on whether the player won/lost. */
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
    
    /* Restarts game from the beginning. */
    main();
}		
