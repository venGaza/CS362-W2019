#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
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
 * - the embargo card places an embargo token on copper
 * - the embargo card added 2 coins to the game state
 * - the embargo card token forces player 2 to receive curse when drawing copper
 * - the embargo card token only affected the copper supply and nothing else
 * - assumes initializeGame() and drawCard have been tested and are working as intended
 * - also assumes the buyCard within is functioning as intended
 */

int main() {
    int testsPassed = 0; 
    int result = -1;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;
    int coinsBefore = 0;
    int coinsAfter = 0;
    
    // Initialize game with 4 players, 10 cards, seed of 5, and named G
    struct gameState G;
    memset (&G, '\0' , sizeof(struct gameState));
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(4, k, 5, &G);
    G.whoseTurn = 0; 
    coinsBefore = G.coins; 

    // Place embargo card in player 1's hand and place embargo on copper supply
    G.hand[0][0] = embargo;
    result = cardEffect(embargo, copper, choice2, choice3, &G, handPos, &bonus);

    G.whoseTurn = 1;

    // Check that embargo correctly marked copper as having an embargo
    result = G.embargoTokens[copper];
    if (result == 1) {
        printf("embargo() correctly placed token on copper pile [1]: PASSED\n");
        testsPassed++;
    } else {
        printf("embargo() correctly placed token on copper pile [1]: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Check to see if 2 coins were added to state
    coinsAfter = G.coins;
    if (coinsAfter > coinsBefore + 1) {
        printf("embargo() added 2 coins to player's pile: PASSED\n");
        testsPassed++;
    } else {
        printf("embargo() added 2 coins to player's pile: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Add a copper to player 2's hand which should also add curse
    G.whoseTurn = 1;
    G.coins = 100;
    buyCard(copper, &G);
    result = fullDeckCount(1, curse, &G);
    if (result == 1) {
        printf("embargo() added curse to player 2 when drawing copper: PASSED\n");
        testsPassed++;
    } else {
        printf("embargo() added curse to player 2 when drawing copper: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Add a gold to player 2's hand which should not add another curse
    buyCard(gold, &G);
    result = fullDeckCount(1, curse, &G);
    if (result == 1) {
        printf("embargo() player 2 should still only have 1 curse: PASSED\n");
        testsPassed++;
    } else {
        printf("embargo() player 2 should still only have 1 curse: FAILED\n");
        printf("***** Returned %d instead of 1 *****\n", result);
    }

    fflush(stdout);

    // Print out number of tests passed
    printf("cutpurse() PASSED %d out of 4 tests\n\n", testsPassed);
    fflush(stdout);

    return 0; 
}