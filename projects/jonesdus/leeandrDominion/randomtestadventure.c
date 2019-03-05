#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
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
 * The following unit test makes use of a random test generator function to create parameter for the adventurer 
 * card effect.
 */

void randomTestAdventure (struct gameState* G) {
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
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
    
    // Random deck count *Causes trap error:6
    //G->deckCount[G->whoseTurn] = rand() % 8;

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
    int handCoinsBefore = 0;
    int handCoinsAfter = 0;
    int numHandCardsBefore = 0;
    int numHandCardsAfter = 0;

    // Initialize game with 4 players, 10 cards, seed of 5, and named G
    struct gameState G;
    memset (&G, '\0' , sizeof(struct gameState));
    
    for (i = 0; i < 20; i++) {
        // Randomize the initial gamestate
        randomTestAdventure(&G);

        // Check coins and number of cards for current player before adventurer is played
        handCoinsBefore = countHandCoins(G.whoseTurn, &G);
        numHandCardsBefore = numHandCards(&G);

        // Run the adventurer card on the gamestate
        cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, &bonus);

        // Check count after adventurer was played
        handCoinsAfter = countHandCoins(G.whoseTurn, &G);
        numHandCardsAfter = numHandCards(&G);

        // Print results
        printf("Test #%d\n", testNum);

        // Should have at least 2 extra coins in hand than before
        if (handCoinsAfter >= (handCoinsBefore + 2)) {
            printf("Test %d: At least 2 extra coins Passed\n", (testNum));
        } else {
            printf("Test %d: At least 2 extra coins FAILED\n", (testNum));
            printf("FAILED STATE: Coin count after: %d Coin count Before: %d\n", handCoinsAfter, handCoinsBefore);
        }

        // Should have 1 more card than before (2 treasure cards added and discard adventurer)
        if (numHandCardsAfter == (numHandCardsBefore + 1)) {
            printf("Test %d: Card Count in player's hand Passed\n", (testNum));
        } else {
            printf("Test %d: Card Count in player's hand FAILED\n", (testNum));
            printf("FAILED STATE: Hand cards after: %d Hand Cards Before: %d\n", numHandCardsAfter, numHandCardsBefore);
        }

        printf("-------------------\n");

        // Reset for next round
        testNum++;
        memset (&G, '\0' , sizeof(struct gameState));
    }
    
    return 0;
}