#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
 * The following unit test uses a random test generator to create a random game state to test the
 * functionality of the smithy card effect. 
 */

void randomTestSmithy (struct gameState* G) {
    int k[10] = {smithy, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
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
    int discardCountBefore = 0;
    int discardCountAfter = 0;
    int numHandCardsBefore = 0;
    int numHandCardsAfter = 0;

    // Initialize game with 4 players, 10 cards, seed of 5, and named G
    struct gameState G;
    memset (&G, '\0' , sizeof(struct gameState));
    
    for (i = 0; i < 100; i++) {
        // Randomize the initial gamestate
        randomTestSmithy(&G);

        // Check number of cards for current player before adventurer is played
        discardCountBefore = G.discardCount[G.whoseTurn];
        numHandCardsBefore = numHandCards(&G);

        // Run the adventurer card on the gamestate
        cardEffect(smithy, choice1, choice2, choice3, &G, handPos, &bonus);

        // Check count after adventurer was played
        discardCountAfter = G.discardCount[G.whoseTurn];
        numHandCardsAfter = numHandCards(&G);

        // Print results
        if (numHandCardsAfter == (numHandCardsBefore + 1)) {
            printf("Test %d: Card Count Passed ", (testNum));
        } else {
            printf("Test %d: Card Count Failed ", (testNum));
        }

        if (discardCountAfter == (discardCountBefore + 1)) {
            printf("Test %d: Discard Count Passed\n", (testNum));
        } else {
            printf("Test %d: Discard Count Failed\n", (testNum));
        }

        // Reset for next round
        testNum++;
        memset (&G, '\0' , sizeof(struct gameState));
    }

    return 0;
}