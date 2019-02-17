#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
 * Function: embargo()
 * --------------------------------------------
 * int embargoEffect(int currentPlayer, struct gameState* state, int handPos, int choice1) {
  //+2 Coins
  state->coins = state->coins + 2;
			
  //see if selected pile is in play
  if ( state->supplyCount[choice1] == -1 ) {
	  return -1;
    }
			
  //add embargo token to selected supply pile
  state->embargoTokens[choice1] = 0;
  
  //trash card
  discardCard(handPos, currentPlayer, state, 1);		
  return 0;
}
    int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
 * --------------------------------------------
 * This card places an embargo token on the supply pile of the player's choice. It also gives the player
 * 2 coins when used.  
 * 
 * The following unit test will check for the following:
 */

void randomTestGenerator () {

}

int main () {


    return 0;
}