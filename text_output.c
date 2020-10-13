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

void intro_text(void) {
	tinygl_init (PACER_RATE);
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set (40);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_ROTATE);
    tinygl_text("  ROCK PAPER SCISSORS 11");
}

void display_result(char result) {
	if (result == 'd') {
		tinygl_text("  DRAW");
	} else if (result == 'w') {
		tinygl_text("  WIN");
	} else if (result == 'l') {
		tinygl_text(" LOSS");
	}

	int counter = 0;
	while (counter < 1500) {
		pacer_wait();
		tinygl_update();
		counter++;
	}
}

void display_score(int score) {
    char char_score = score + '0';
    char* text = "  SCORE: ";
    text[9] = char_score;
    text[10] = '\0';
    tinygl_text(text);   

    int counter = 0;
	while (counter < 1750) {
		pacer_wait();
		tinygl_update();
		counter++;
	}
}
