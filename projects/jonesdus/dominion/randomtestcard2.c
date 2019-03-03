#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
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

void randomTestEmbargo (struct gameState* G) {
    int k[10] = {embargo, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int numPlayers;
    int seed;

    // Random number of players
    numPlayers = (rand() % 3) + 2;

    // Random seed
    seed = (rand() % 100) + 1;

    //Initialize base game
    initializeGame(numPlayers, k, seed, G);
    
    // Random Turn
    G->whoseTurn = rand() % numPlayers;
}

int main () {
    srand(time(NULL));
    int i = 0;
    int testNum = 1;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;
    int result = 0;
    int discardCountBefore = 0;
    int discardCountAfter = 0;
    int coinCountBefore = 0;
    int coinCountAfter = 0;
    int numHandCardsBefore = 0;
    int numHandCardsAfter = 0;

    // Initialize game with 4 players, 10 cards, seed of 5, and named G
    struct gameState G;
    memset (&G, '\0' , sizeof(struct gameState));
    
    for (i = 0; i < 100; i++) {
        // Randomize the initial gamestate
        randomTestEmbargo(&G);
        choice1 = rand() % 25;

        // Check number of cards and coins for current player before embargo is played
        discardCountBefore = G.discardCount[G.whoseTurn];
        numHandCardsBefore = numHandCards(&G);
        coinCountBefore = countHandCoins(G.whoseTurn, &G);

        // Run the embargo card on the gamestate
        result = cardEffect(embargo, choice1, choice2, choice3, &G, handPos, &bonus);

        // Check count after embargo was played
        discardCountAfter = G.discardCount[G.whoseTurn];
        numHandCardsAfter = numHandCards(&G);
        coinCountAfter = countHandCoins(G.whoseTurn, &G);

        // Print results
        printf("Test #%d\n", testNum);

        if (numHandCardsAfter == (numHandCardsBefore - 1)) {
            printf("Test %d: Hand card Count Passed\n", (testNum));
        } else {
            printf("Test %d: Hand card Count FAILED\n", (testNum));
        }

        if (discardCountAfter == (discardCountBefore + 1)) {
            printf("Test %d: Discard Count Passed\n", (testNum));
        } else {
            printf("Test %d: Discard Count FAILED\n", (testNum));
        }

        if (G.supplyCount[choice1] == -1) {
            if (result == -1) {
                printf("Test %d: Embargo caught bad supply choice Passed\n", (testNum));
            } else {
                printf("Test %d: Embargo caught bad supply choice FAILED\n", (testNum));
            }
        } else {
            if (G.embargoTokens[choice1] == 1) {
                printf("Test %d: Embargo token placed Passed\n", (testNum));
            } else {
                printf("Test %d: Embargo toke placed FAILED\n", (testNum));
            }
        }

        if (coinCountAfter == (coinCountAfter + 2)) {
            printf("Test %d: Coins added Passed\n", (testNum));
        } else {
            printf("Test %d: Coins added FAILED\n", (testNum));
        }

        printf("-------------------\n");

        // Reset for next round
        testNum++;
        memset (&G, '\0' , sizeof(struct gameState));
    }

    return 0;
}