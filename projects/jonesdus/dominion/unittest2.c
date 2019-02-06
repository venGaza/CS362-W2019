#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
 * Function: isGameOver()
 * --------------------------------------------
 * int isGameOver(struct gameState *state) {
  int i;
  int j;
	
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
}
 * --------------------------------------------
 * This function checks to see if one of the end of game conditions has been met which are no more
 * province cards or 3 supply stacks being empty. 
 * 
 * The following unit test will check for the following:
 * - the function returns the correct value after a game initialiation (full province and supply stacks)
 * - the function returns the correct value when province pile depleted
 * - the function returns the correct value when province available and one supply depleted
 * - the function returns the correct value when province available and two supply depleted
 * - the function returns the correct value when province available and three supply depleted
 * - the function returns the correct value when province not available and three supply depleted
 * - assumes initializeGame() has been tested and is working as intended
 */

int main() {
    int testsPassed = 0; 
    int result = -1;

    // Initialize game with 4 players, 10 cards, seed of 5, and named G
    struct gameState G;
    memset (&G, '\0' , sizeof(struct gameState));
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(4, k, 5, &G);

    // Test the isGameOver function
    printf("TESTING isGameOver():\n");

    // Province cards are available and no supply stacks empty
    result = isGameOver(&G);
    if (result == 0) {
        printf("isGameOver() returns correct value [0] after initialization: PASSED\n");
        testsPassed++;
    } else {
        printf("isGameOver() returns correct value [0] after initialization: FAILED\n");
        printf("***** Returned %d instead of 0 *****\n", result);
    }

    fflush(stdout);

    // Province cards are empty and all other supply stacks full; game over!
    G.supplyCount[province] = 0;
    result = isGameOver(&G);
    if (result == 1) {
        printf("isGameOver() returns correct value [1] when province stack empty: PASSED\n");
        testsPassed++;
    } else {
        printf("isGameOver() returns correct value [1] when province stack empty: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);
    G.supplyCount[province] = 8; // Reset province cards for next test
    
    // Province cards are available and one supply stack is empty
    G.supplyCount[curse] = 0;
    result = isGameOver(&G);
    if (result == 0) {
        printf("isGameOver() returns correct value [0] when province available and one supply stack empty: PASSED\n");
        testsPassed++;
    } else {
        printf("isGameOver() returns correct value [0] when province available and one supply stack empty: FAILED\n");
        printf("***** Returned %d instead of 0 *****\n", result);
    }

    fflush(stdout);

    // Province cards are available and two supply stacks is empty
    G.supplyCount[estate] = 0;
    result = isGameOver(&G);
    if (result == 0) {
        printf("isGameOver() returns correct value [0] when province available and two supply stacks empty: PASSED\n");
        testsPassed++;
    } else {
        printf("isGameOver() returns correct value [0] when province available and two supply stacks empty: FAILED\n");
        printf("***** Returned %d instead of 0 *****\n", result);
    }

    fflush(stdout);

    // Province cards are available and three supply stacks is empty; game over! 
    G.supplyCount[duchy] = 0;
    result = isGameOver(&G);
    if (result == 1) {
        printf("isGameOver() returns correct value [1] when province available and three supply stacks empty: PASSED\n");
        testsPassed++;
    } else {
        printf("isGameOver() returns correct value [1] when province available and three supply stacks empty: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Province cards are not available and three supply stacks is empty; game over! 
    G.supplyCount[province] = 0;
    result = isGameOver(&G);
    if (result == 1) {
        printf("isGameOver() returns correct value [1] when province not available and three supply stacks empty: PASSED\n");
        testsPassed++;
    } else {
        printf("isGameOver() returns correct value [1] when province not available and three supply stacks empty: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Print out number of tests passed
    printf("isGameOver() PASSED %d out of 6 tests\n\n", testsPassed);
    fflush(stdout);

    return 0;
}