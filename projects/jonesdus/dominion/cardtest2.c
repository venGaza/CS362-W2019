#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
 * Function: adventurer()
 * --------------------------------------------
 * int adventurerEffect(struct gameState* state, int currentPlayer, int cardDrawn, int drawntreasure, int temphand [], int z) {
  while(drawntreasure<2){
    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure+=2;
    else{
      temphand[z]=cardDrawn;
      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      z++;
	  }
  }

  while(z-1>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    z=z-1;
  }
  
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
 */

int main() {
    int testsPassed = 0; 
    int result = -1;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;

    // Initialize game with 4 players, 10 cards, seed of 5, and named G
    struct gameState G;
    memset (&G, '\0' , sizeof(struct gameState));
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(4, k, 5, &G);
    G.whoseTurn = 0; 

    // Add adventurer card to player 1 hand (has 5 cards in hand from initialization) and play it
    G.hand[0][0] = adventurer;
    result = cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, &bonus);

    

    return 0;
}