/** @file   text_output.c
    @author Michael Woodard and Sean Lalor
    @date   10 Oct 2020
    @brief  This is used to display all the textual
            outputs for the game except for the
            end game text.
*/


#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font3x5_1.h"

#define PACER_RATE 500 /* Pacer rate for the welcoming text. */
#define INTRO_TEXT_SPEED 40 /* Text speed for the welcoming text. */
#define RESULT_RATE 1500 /* Text rate for the result text. */
#define SCORE_RATE 1750 /* Text rate for the score text. */

/* Displays the welcoming screen text for the game. */
void intro_text(void) {
	tinygl_init (PACER_RATE);
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set (INTRO_TEXT_SPEED);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_ROTATE);
    tinygl_text("  ROCK PAPER SCISSORS 11");
}

/* Displays the result of the two player's option
   comparisons. This display is different depending on whether
   the player won/lost. */
void display_result(char result) {
	if (result == 'd') {
		tinygl_text("  DRAW");
	} else if (result == 'w') {
		tinygl_text("  WIN");
	} else if (result == 'l') {
		tinygl_text(" LOSS");
	}

	int counter = 0;
	while (counter < RESULT_RATE) {
		pacer_wait();
		tinygl_update();
		counter++;
	}
}

/* Displays the player's current score. */
void display_score(int score) {
    char char_score = score + '0';
    char* score_text = "  SCORE: ";
    score_text[9] = char_score;
    score_text[10] = '\0';
    tinygl_text(score_text);   

    int counter = 0;
	while (counter < SCORE_RATE) {
		pacer_wait();
		tinygl_update();
		counter++;
	}
}
