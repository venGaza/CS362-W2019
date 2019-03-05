#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
 * Function: cutpurse()
 * --------------------------------------------
 * int cutpurseEffect(int currentPlayer, struct gameState* state, int handPos, int i, int j, int k) {
  updateCoins(currentPlayer, state, 2);
  for (i = 0; i < state->numPlayers; i++) {
	  if (i != currentPlayer) {
      for (j = 0; j < state->handCount[i]; j++) {
        if (state->hand[i][j] == gold) {
          discardCard(j, i, state, 0);
          break;
        }

        if (j == state->handCount[i]) {
            for (k = 0; k < state->handCount[i]; k++) {
              if (DEBUG)
                printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
            }	
            break;
        }		
      }		
	  }		
	}		

    int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
 * --------------------------------------------
 * This function forces players to discard a copper from their hand.  
 * 
 * The following unit test will check for the following:
 * - the cutpurse card discards itself after being used
 * - the cutpurse card takes copper from player 2
 * - the cutpurse card takes copper from player 3
 * - the cutpurse card takes copper from player 4
 * - the cutpurse card did not take a copper from player 1
 * - the cutpurse card takes only copper and not a gold
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
    int i, j;
    int handcoins = 0;
    
    // Initialize game with 4 players, 10 cards, seed of 5, and named G
    struct gameState G;
    memset (&G, '\0' , sizeof(struct gameState));
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(4, k, 5, &G);
    G.whoseTurn = 0; 

    // Put copper in player 1, 2, 3, and 4 hands
    for (i = 0; i < 4; i++) {
        for(j = 0; j < 2; j++) {
            G.hand[i][j] = copper;
        }
    }

    // Replace player 1's 1st card with cutpurse and play it
    G.hand[0][0] = cutpurse;
    result = cardEffect(cutpurse, choice1, choice2, choice3, &G, handPos, &bonus);

    // Cutpurse card was discarded
    result = numHandCards(&G);
    if (result == 1) {
        printf("cutpurse() was discarded after being played [1]: PASSED\n");
        testsPassed++;
    } else {
        printf("cutpurse() adds correct amount of cards and discards excess [6]: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Cutpurse took copper from player 2
    G.whoseTurn = 1; 
    handcoins = countHandCoins(1, &G);
    if (handcoins == 1) {
        printf("cutpurse() removed copper from player 2 [1]: PASSED\n");
        testsPassed++;
    } else {
        printf("cutpurse() removed copper from player 2 [1]: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Cutpurse took copper from player 3
    G.whoseTurn = 2; 
    handcoins = countHandCoins(2, &G);
    if (handcoins == 1) {
        printf("cutpurse() removed copper from player 3 [1]: PASSED\n");
        testsPassed++;
    } else {
        printf("cutpurse() removed copper from player 3 [1]: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Cutpurse took copper from player 4
    G.whoseTurn = 3; 
    handcoins = countHandCoins(3, &G);
    if (handcoins == 1) {
        printf("cutpurse() removed copper from player 4 [1]: PASSED\n");
        testsPassed++;
    } else {
        printf("cutpurse() removed copper from player 4 [1]: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Cutpurse did not take copper from player 1
    G.whoseTurn = 0; 
    handcoins = countHandCoins(0, &G);
    if (handcoins == 1) {
        printf("cutpurse() did not take copper from player 1 [1]: PASSED\n");
        testsPassed++;
    } else {
        printf("cutpurse() did not take copper from player 1 [1]: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    //Place gold and copper in player 2's hand
    G.hand[1][0] = gold;
    G.hand[1][1] = copper;
    G.whoseTurn = 1;

    // Replace player 1's 1st card with cutpurse and play it
    G.hand[0][0] = cutpurse;
    result = cardEffect(cutpurse, choice1, choice2, choice3, &G, handPos, &bonus);

    // Count player 2's hand
    handcoins = countHandCoins(1, &G);
    if (handcoins == 3) {
        printf("cutpurse() did not take gold over copper from player 2 [3]: PASSED\n");
        testsPassed++;
    } else {
        printf("cutpurse() did not take gold over copper from player 2 [3]: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Print out number of tests passed
    printf("cutpurse() PASSED %d out of 6 tests\n\n", testsPassed);
    fflush(stdout);

    return 0;
}