/** @file   choice.h
    @author Michael Woodard and Sean Lalor
    @date   10 Oct 2020
    @brief  This interface is used to send/convert the 
            player's sent/received option.
*/

#ifndef CHOICE_H
#define CHOICE_H

#include "system.h"
#include "ir_uart.h"

/* Converts the player's selected option to
   a character between 'A' and 'K', which is 
   then sent to the other player. */
void send_choice(int player_choice);

/* Converts the received character sent through
   the send_choice function to an int between 
   0 and 10. */
int convert_recieved(char ch);

#endif
