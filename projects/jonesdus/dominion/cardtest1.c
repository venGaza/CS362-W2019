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

    // Add smithy card to player 1 hand (has 5 cards in hand from initialization) and play it
    G.hand[0][0] = smithy;
    result = cardEffect(smithy, choice1, choice2, choice3, &G, handPos, &bonus);

    // Check if player has correct number of cards 5 + 3 - 1(smithy) = 7
    result = numHandCards(&G);
    if (result == 7) {
        printf("smithyCard() returns correct value [7] after being played: PASSED\n");
        testsPassed++;
    } else {
        printf("smithyCard() returns correct value [7] after being played: FAILED\n");
        printf("***** Returned %d instead of 7 *****\n", result);
    }

    fflush(stdout);

    // Check if smithy card was discarded to the right pile (should be only discard)
    if (G.discardCount[0] == 1) {
        printf("smithyCard() was discarded to right pile: PASSED\n");
        testsPassed++;
    } else {
        printf("smithyCard() was discarded to right pile: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", G.discardCount[0]);
    }

    fflush(stdout);

    // Check to see if smithy card drew cards from the right pile (should be two cards left)
    if (G.deckCount[0] == 2) {
        printf("smithyCard() drew cards from the right pile: PASSED\n");
        testsPassed++;
    } else {
        printf("smithyCard() drew cards from the right pile right pile: FAILED\n");
        printf("***** Returned %d instead of 2 *****\n", G.deckCount[0]);
    }

    fflush(stdout);

    // Check to see that the right card was discarded
    if (G.discard[0][0] == smithy) {
        printf("smithyCard() discarded the correct card: PASSED\n");
        testsPassed++;
    } else {
        printf("smithyCard() discarded the correct card: FAILED\n");
        printf("***** Returned %d instead of 0 *****\n", G.discard[0][0]);
    }

    fflush(stdout);

    // Print out number of tests passed
    printf("smithy() PASSED %d out of 4 tests\n\n", testsPassed);
    fflush(stdout);

     return 0;
 }