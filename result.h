/** @file   result.h
    @author Michael Woodard and Sean Lalor
    @date   10 Oct 2020
    @brief  This interface is used to compare the two player's
            options to determine a winner.
*/

#ifndef RESULT_H
#define RESULT_H

#include "system.h"

/* Compares the player's choice with his/her opponents choice
   to determine a winner. Each int corresponds to a certain 
   option, which can be seen in the player_options struct in
   game.c. Explanation on which options win/lose to other options
   is in the README. A character 'w', 'd', or 'l is returned 
   corresponding to a win, draw or loss. */
char check_result(int player_choice, int oc);

/* Converts the opponents win/loss to a loss/win.
   If this was not done both player's would think
   they have won/lost. */
char received_result(char result);

#endif
