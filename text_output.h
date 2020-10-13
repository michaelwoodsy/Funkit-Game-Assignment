/** @file   text_output.h
    @author Michael Woodard and Sean Lalor
    @date   10 Oct 2020
    @brief  This is the interface used to display all the textual
            outputs for the game except for the end game text.
*/

#ifndef TEXT_OUTPUT_H
#define TEXT_OUTPUT_H

#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font3x5_1.h"

#define PACER_RATE 500 /* Pacer rate for the welcoming text. */
#define INTRO_TEXT_SPEED 40 /* Text speed for the welcoming text. */
#define RESULT_RATE 1500 /* Text rate for the result text. */
#define SCORE_RATE 1750 /* Text rate for the score text. */

/* Displays the welcoming screen text for the game. */
void intro_text(void);

/* Displays the result of the two player's option
   comparisons. This display is different depending on whether
   the player won/lost. */
void display_result(char result);

/* Displays the player's current score. */
void display_score(int score);

#endif
