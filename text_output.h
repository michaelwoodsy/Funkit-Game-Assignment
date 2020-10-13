/** @file   game.c
    @author Michael Woodard and Sean Lalor
    @date   7 Oct 2020
    @note   does nothing
*/
#ifndef TEXT_OUTPUT_H
#define TEXT_OUTPUT_H

#include "system.h"
#include "tinygl.h"
#include "navswitch.h"
#include "pacer.h"
#include "ir_uart.h"
#include "pio.h"
#include "../fonts/font3x5_1.h"

#define PACER_RATE 500

void intro_text(void);

void display_result(char result);

void display_score(int score);

void end_text(int score);

#endif
