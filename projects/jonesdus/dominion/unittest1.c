#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
 * Function: whoseTurn()
 * --------------------------------------------
 * int whoseTurn(struct gameState *state) {
        return state->whoseTurn;
 * --------------------------------------------
 * This function returns an integer value from the game state struct which corresponds to which 
 * player's turn it is. 
 * 
 * The following unit test will check for the following:
 * - the function returns the correct value after a game initialiation
 * - the function returns the correct value after an end turn
 * - the function returns the correct value of an arbitrarily set turn number
 * - assumes initializeGame() and endTurn() have been tested and are working as intended
 */

int main() {
    int turnEnd = 0;
    int turnNum = -1;
    int testsPassed = 0;

    // Initialize game with 4 players, 10 cards, seed of 5, and named G
    struct gameState G;
    memset (&G, '\0' , sizeof(struct gameState));
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(4, k, 5, &G);

    // Test the whoseTurn function
    printf("TESTING whoseTurn():\n");

    // Player 1 (0) is the starting player after initialization
    turnNum = whoseTurn(&G);
    if (whoseTurn(&G) == 0) {
        printf("whoseTurn() returns correct value [0] after initialization: PASSED\n");
        testsPassed++;
    } else {
        printf("whoseTurn() returns correct value [0] after initialization: FAILED\n");
        printf("***** Returned %d instead of 0 *****\n", turnNum);
    }

    fflush(stdout);

    // It is player 2's turn after running the endTurn() function
    turnEnd = endTurn(&G);
    assert(turnEnd == 0);
    turnNum = whoseTurn(&G);

    if (turnNum == 1) {
        printf("whoseTurn() returns correct value [1] after the end of a turn: PASSED\n");
        testsPassed++;
    } else {
        printf("whoseTurn() returns correct value [1] after the end of a turn: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", turnNum);
    }

    fflush(stdout);

    // whoseTurn() returns the correct value of arbitrarily set turn value
    G.whoseTurn = 100;
    turnNum = whoseTurn(&G);
    if (turnNum == 100) {
        printf("whoseTurn() returns arbitrary turn value [100]: PASSED\n");
        testsPassed++;
    } else {
        printf("whoseTurn() returns arbitrary turn value [100]: FAILED\n");
        printf("***** Returned %d instead of 100 *****\n", turnNum);
    }

    fflush(stdout);

    // Print out number of tests passed
    printf("whoseTurn() PASSED %d out of 3 tests\n\n", testsPassed);
    fflush(stdout);

    return 0;
}