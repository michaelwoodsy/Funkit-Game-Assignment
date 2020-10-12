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

#define PACER_RATE 500

static const char* player_options[] =
{
	"  ROCK", "  FIRE", "  SCISSORS", "  HUMAN", "  WOLF",
	"  SPONGE", "  PAPER", "  AIR", "  WATER", "  DEVIL", "  GUN"
};


void intro_text() {
	tinygl_init (PACER_RATE);
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set (40);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_ROTATE);
    tinygl_text("  ROCK PAPER SCISSORS 11");
}

void send_choice(int player_choice) {
	if (player_choice == 0) {
		ir_uart_putc('A');
	} else if (player_choice == 1) {
		ir_uart_putc('B');
	} else if (player_choice == 2) {
		ir_uart_putc('C');
	} else if (player_choice == 3) {
		ir_uart_putc('D');
	} else if (player_choice == 4) {
		ir_uart_putc('E');
	} else if (player_choice == 5) {
		ir_uart_putc('F');
	} else if (player_choice == 6) {
		ir_uart_putc('G');
	} else if (player_choice == 7) {
		ir_uart_putc('H');
	} else if (player_choice == 8) {
		ir_uart_putc('I');
	} else if (player_choice == 9) {
		ir_uart_putc('J');
	} else {
		ir_uart_putc('K');
	}
}	

int convert_recieved(char ch) {
	if (ch == 'A') {
		return 0;
	} else if (ch == 'B') {
		return 1;
	} else if (ch == 'C') {
		return 2;
	} else if (ch == 'D') {
		return 3;
	} else if (ch == 'E') {
		return 4;
	} else if (ch == 'F') {
		return 5;
	} else if (ch == 'G') {
		return 6;
	} else if (ch == 'H') {
		return 7;
	} else if (ch == 'I') {
		return 8;
	} else if (ch == 'J') {
		return 9;
	} else {
		return 10;
	}
}

char check_result(player_choice, oc) {
	if (player_choice == oc) {
		return 'd';
	} else if (player_choice == 0) {
		if (oc == 1 | oc == 2 | oc == 3 | oc == 4 | oc == 5) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 1) {
		if (oc == 2 | oc == 3 | oc == 4 | oc == 5 | oc == 6) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 2) {
		if (oc == 3 | oc == 4 | oc == 5 | oc == 6 | oc == 7) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 3) {
		if (oc == 4 | oc == 5 | oc == 6 | oc == 7 | oc == 8) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 4) {
		if (oc == 5 | oc == 6 | oc == 7 | oc == 8 | oc == 9) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 5) {
		if (oc == 6 | oc == 7 | oc == 8 | oc == 9 | oc == 10) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 6) {
		if (oc == 7 | oc == 8 | oc == 9 | oc == 10 | oc == 0) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 7) {
		if (oc == 8 | oc == 9 | oc == 10 | oc == 0 | oc == 1) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 8) {
		if (oc == 9 | oc == 10 | oc == 0 | oc == 1 | oc == 2) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 9) {
		if (oc == 10 | oc == 0 | oc == 1 | oc == 2 | oc == 3) {
			return 'w';
		} else {
			return 'l';
		}
	} else if (player_choice == 10) {
		if (oc == 0 | oc == 1 | oc == 2 | oc == 3 | oc == 4) {
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

void display_result(char result) {
	if (result == 'd') {
		tinygl_text("  DRAW");
	} else if (result == 'w') {
		tinygl_text("  WIN");
	} else if (result == 'l') {
		tinygl_text(" LOSS");
	}
	

	int i = 0;
	while (i < 1500) {
		pacer_wait();
		tinygl_update();
		i++;
	}
}

void display_score(int score) {
    char char_score = score + '0';
    char* text = "  SCORE: ";
    text[9] = char_score;
    text[10] = '\0';
    tinygl_text(text);   

    int i = 0;
	while (i < 1750) {
		pacer_wait();
		tinygl_update();
		i++;
	}
}
	

int main(void) {
	system_init();
	ir_uart_init();
	intro_text();
	pacer_init(PACER_RATE);
	while (1) {
		pacer_wait();
		tinygl_update();
		navswitch_update();
		if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
			break;
		}
	}
    int score = 0;
	int player_choice = 0;
	int previous_choice = player_choice;
	tinygl_text(player_options[player_choice]);
	bool recieve_state = false;
	while (1) {
	
		if (!recieve_state) {
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
				recieve_state = true;
			}
			if (ir_uart_read_ready_p()) {	
				char ch = ir_uart_getc();
				if (isalpha(ch)) {
					int opp_choice = convert_recieved(ch);
					char result = check_result(player_choice, opp_choice);
					ir_uart_putc(result);
                    if (result == 'w') {
                        score++;
                        if (score == 3) {
                            break;
                        }
                    }
					display_result(result);
                    display_score(score);
					previous_choice = -1;
				} else if (ch == '!') {
                    break;
                }
			}
		} else {
			if (ir_uart_read_ready_p()) {	
				char ch = ir_uart_getc();
				if (ch == 'l' | ch == 'd' | ch == 'w') {
					char result = received_result(ch);
                    if (result == 'w') {
                        score++;
                        if (score == 3) {
                            break;
                        }
                    }
					display_result(result);
                    display_score(score);
					recieve_state = false;
					previous_choice = -1;
				} else if (ch == '!') {
                    break;
                }	
			}
		}
	}
    while (1) {
        if (score == 3) {
            ir_uart_putc('!');
            tinygl_text("  CONGRATULATIONS, YOU WON!");   
            int i = 0;
	        while (i < 5000) {
		        pacer_wait();
		        tinygl_update();
		        i++;
	        }
        } else {
            tinygl_text("  HARDLUCK, YOU LOST :(");   
            int i = 0;
	        while (i < 5000) {
		        pacer_wait();
		        tinygl_update();
		        i++;
	        }
        }
    } 
}		
