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
