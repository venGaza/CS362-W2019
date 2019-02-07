#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
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
 * This function allows player to draw cards from their deck until it finds 2 treasures to add
 * to the current hand. Non treasure cards that are drawn are placed in the player's discard pile. 
 * 
 * The following unit test will check for the following:
 * - the adventurer card increased hand value by 2 coppers
 * - the adventurer card has increased hand count by 2
 * - the adventurer card discard to discard pile
 * - the adventurer card places non treasure cards in player's discard pile
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
    int handCoinsBefore = 0;
    int handCoinsAfter = 0;
    // Initialize game with 4 players, 10 cards, seed of 5, and named G
    struct gameState G;
    memset (&G, '\0' , sizeof(struct gameState));
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(4, k, 5, &G);
    G.whoseTurn = 0; 

    // Add adventurer card to player 1 hand (has 5 cards in hand from initialization) and play it
    G.hand[0][0] = adventurer;
    handCoinsBefore = countHandCoins(0, &G);
    result = cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, &bonus);
    
    // Count current handCoins
    handCoinsAfter = countHandCoins(0, &G); 

    // Check to see if player 1 has two extra copper in hand
    if (handCoinsAfter > handCoinsBefore + 1) {
        printf("adventurer() has drawn the correct amount of treasure: PASSED\n");
        testsPassed++;
    } else {
        printf("adventurer() has drawn the correct amount of treasure: FAILED\n");
        printf("***** Returned before: %d after: %d *****\n", handCoinsBefore, handCoinsAfter);
    }

    fflush(stdout);

    // Check to see if there are two extra cards in player 1's hand
    result = numHandCards(&G);
    if (result == 7) {
        printf("adventurer() adds correct amount of cards and discards excess [6]: PASSED\n");
        testsPassed++;
    } else {
        printf("adventurer() adds correct amount of cards and discards excess [6]: FAILED\n");
        printf("***** Returned %d instead of 6 *****\n", result);
    }

    fflush(stdout);

    // Check player 1 deck not empty
    result = G.deckCount[0];
    if (result != 0) {
        printf("adventurer() shuffled deck when depleted: PASSED\n");
        testsPassed++;
    } else {
        printf("adventurer() shuffled deck when depleted: FAILED\n");
        printf("***** Returned %d instead of >1 *****\n", result);
    }

    fflush(stdout);

    // Check player hand cards placed in discard pile
    if (G.discard[0][0] == adventurer) {
        printf("adventurer() discarded the correct cards: PASSED\n");
        testsPassed++;
    } else {
        printf("adventurer() discarded the correct cards: FAILED\n");
        printf("***** Returned %d instead of 0 *****\n", G.discard[0][0]);
    }

    fflush(stdout);

    // Print out number of tests passed
    printf("adventurer() PASSED %d out of 4 tests\n\n", testsPassed);
    fflush(stdout);

    return 0;
}