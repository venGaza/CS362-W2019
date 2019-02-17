#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
 * Function: smithy()
 * --------------------------------------------
 * int smithyEffect(int currentPlayer, struct gameState* state, int handPos, int i) {
     //+3 Cards
      for (i = 0; i < 4; i++) {
          drawCard(currentPlayer, state);
      }
			
    //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
    }
    int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
 * --------------------------------------------
 * This function allows player to draw 3 cards from deck and then is discarded.  
 * 
 * The following unit test will check for the following:
 * - the smithy card draws the right number of cards
 * - the smithy card discards to the correct pile
 * - the smithy card draws from the correct pile
 * - the smithy card discarded itself and not another card
 * - assumes initializeGame() and drawCard have been tested and are working as intended
 * - also assumes the discardCard within Smithy is functioning as intended
 */

void randomTestGenerator () {
    
}

int main () {


    return 0;
}