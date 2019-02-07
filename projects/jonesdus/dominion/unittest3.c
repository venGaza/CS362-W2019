#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
 * Function: supplyCount()
 * --------------------------------------------
 * int supplyCount(int card, struct gameState *state) {
        return state->supplyCount[card];
   }
 * --------------------------------------------
 * This function returns an integer value for a specified card pile.
 * 
 * The following unit test will check for the following:
 * - the function returns the correct value after a game initialiation
 * - the function returns the correct value after card supply value changed
 * - the function returns the correct value for different supply stack
 * - assumes initializeGame() has been tested and is working as intended
 */

int main() {
    int result = -1;
    int testsPassed = 0;

    // Initialize game with 4 players, 10 cards, seed of 5, and named G
    struct gameState G;
    memset (&G, '\0' , sizeof(struct gameState));
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(4, k, 5, &G);

    // Test the isGameOver function
    printf("TESTING isGameOver():\n");

    // Test to see if the function can return correct number of province cards
    result = supplyCount(province, &G);
    if (result == 12) {
        printf("supplyCount() returns correct value for province stack [12] after initialization: PASSED\n");
        testsPassed++;
    } else {
        printf("supplyCount() returns correct value for province stack [12] after initialization: FAILED\n");
        printf("***** Returned %d instead of 12 *****\n", result);
    }

    fflush(stdout);

    // Test to see if the function can return correct number of province cards when stack is empty
    G.supplyCount[province] = 0;
    result = supplyCount(province, &G);
    if (result == 0) {
        printf("supplyCount() returns correct value for province stack [0] after initialization: PASSED\n");
        testsPassed++;
    } else {
        printf("supplyCount() returns correct value for province stack [0] after initialization: FAILED\n");
        printf("***** Returned %d instead of 0 *****\n", result);
    }

    fflush(stdout);
    G.supplyCount[province] = 12; // Reset province stack to initial

    // Test to see if the function can return correct number of different supply stack
    result = supplyCount(duchy, &G);
    if (result == 12) {
        printf("supplyCount() returns correct value for duchy stack [12] after initialization: PASSED\n");
        testsPassed++;
    } else {
        printf("supplyCount() returns correct value for duchy stack [12] after initialization: FAILED\n");
        printf("***** Returned %d instead of 12 *****\n", result);
    }

    fflush(stdout);

    // Print out number of tests passed
    printf("supplyCount() PASSED %d out of 3 tests\n\n", testsPassed);
    fflush(stdout);

    return 0;
}