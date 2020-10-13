/** @file   choice.c
    @author Michael Woodard and Sean Lalor
    @date   10 Oct 2020
    @brief  This is used to send/convert the 
            player's sent/received option.
*/

#include "system.h"
#include "ir_uart.h"

/* Converts the player's selected option to
   a character between 'A' and 'K', which is 
   then sent to the other player. */
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

/* Converts the received character sent through
   the send_choice function to an int between 
   0 and 10. */
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
