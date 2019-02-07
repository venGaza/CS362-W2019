#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
 * Function: getWinners()
 * --------------------------------------------
 * int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
  int i;	
  int j;
  int highScore;
  int currentPlayer;

  //get score for each player
  for (i = 0; i < MAX_PLAYERS; i++)
    {
      //set unused player scores to -9999
      if (i >= state->numPlayers)
	{
	  players[i] = -9999;
	}
      else
	{
	  players[i] = scoreFor (i, state);
	}
    }

  //find highest score
  j = 0;
  for (i = 0; i < MAX_PLAYERS; i++)
    {
      if (players[i] > players[j])
	{
	  j = i;
	}
    }
  highScore = players[j];

  //add 1 to players who had less turns
  currentPlayer = whoseTurn(state);
  for (i = 0; i < MAX_PLAYERS; i++)
    {
      if ( players[i] == highScore && i > currentPlayer )
	{
	  players[i]++;
	}
    }

  //find new highest score
  j = 0;
  for (i = 0; i < MAX_PLAYERS; i++)
    {
      if ( players[i] > players[j] )
	{
	  j = i;
	}
    }
  highScore = players[j];

  //set winners in array to 1 and rest to 0
  for (i = 0; i < MAX_PLAYERS; i++)
    {
      if ( players[i] == highScore )
	{
	  players[i] = 1;
	}
      else
	{
	  players[i] = 0;
	}
    }

  return 0;
}
 * --------------------------------------------
 * This function determines the winners of the game.
 * 
 * The following unit test will check for the following:
 * - 2nd player wins by getting extra point for high score + less turns
 * - 1st Player wins the game
 * - 2nd Player wins the game
 * - Tie game with 2 winners
 * - 1st Player wins the game with a different hand
 * - assumes scoreFor() has been tested and is working as intended
 */

 int main() {
     int result = -1;
    int testsPassed = 0;

    // Initialize game with 2 players, 10 cards, seed of 5, and named G
    struct gameState G;
    G.numPlayers = 2;
    G.whoseTurn = 0; 
    memset (&G, '\0' , sizeof(struct gameState));
    int players[MAX_PLAYERS];


    // Player 1 
    G.discardCount[0] = 0;
    G.handCount[0] = 0;
    G.deckCount[0] = 0;

    // Player 2
    G.discardCount[1] = 0;
    G.handCount[1] = 0;
    G.deckCount[1] = 0;
   
    // Test the getWinners function
    printf("TESTING getWinners():\n");

    // Player 2 given extra point for having high score and having less turns
    result = getWinners(players, &G);
    if (players[0] == 0 && players[1] == 1) {
        printf("getWinners() returns correct value for 2 player win with high score and less turns: PASSED\n");
        testsPassed++;
    } else {
        printf("getWinners() returns correct value for 2 player win with high score and less turns: FAILED\n");
        printf("***** getWinners() returned player1 = %d and player2 = %d *****", players[0], players[1]);
        printf("***** Score for Player1: %d Score for Player2: %d\n *****", scoreFor(0, &G), scoreFor(1, &G));
    }
    
    fflush(stdout);

    // Player 1 wins withy duchy card (Player1: 3 to Player2: 0)
    G.hand[0][0] = duchy;
	  G.handCount[0]++;

    result = getWinners(players, &G);
    if (players[0] == 1 && players[1] == 0) {
        printf("getWinners() returns correct value for player1 wins game: PASSED\n");
        testsPassed++;
    } else {
        printf("getWinners() returns correct value for player1 wins game: FAILED\n");
        printf("***** getWinners() returned player1 = %d and player2 = %d *****", players[0], players[1]);
        printf("***** Score for Player1: %d Score for Player2: %d\n *****", scoreFor(0, &G), scoreFor(1, &G));
    }

    fflush(stdout);

    // Player 2 wins with province card (Player1: 3 to Player2: 6)
    G.hand[1][0] = province;
	  G.handCount[1]++;

    result = getWinners(players, &G);
    if (players[0] == 0 && players[1] == 1) {
        printf("getWinners() returns correct value for player2 wins game: PASSED\n");
        testsPassed++;
    } else {
        printf("getWinners() returns correct value for player2 wins game: FAILED\n");
        printf("***** getWinners() returned player1 = %d and player2 = %d *****", players[0], players[1]);
        printf("***** Score for Player1: %d Score for Player2: %d\n *****", scoreFor(0, &G), scoreFor(1, &G));
    }

    fflush(stdout);

    // Tie Game state both winners (Player1: 6 to Player2: 6)
    G.whoseTurn = 3; //Point to NULL player
    G.hand[0][1] = duchy;
    G.handCount[0]++;

    result = getWinners(players, &G);
    if (players[0] == 1 && players[1] == 1) {
        printf("getWinners() returns correct value for tie game: PASSED\n");
        testsPassed++;
    } else {
        printf("getWinners() returns correct value for tie game: FAILED\n");
        printf("***** getWinners() returned player1 = %d and player2 = %d *****", players[0], players[1]);
        printf("***** Score for Player1: %d Score for Player2: %d\n *****", scoreFor(0, &G), scoreFor(1, &G));
    }

    fflush(stdout);

    // Player 1 takes the lead again (Player1: 7 to Player2: 6)
    G.hand[0][2] = estate;
    G.handCount[1]++;

    result = getWinners(players, &G);
    if (players[0] == 1 && players[1] == 0) {
        printf("getWinners() returns correct value for player 1 wins: PASSED\n");
        testsPassed++;
    } else {
        printf("getWinners() returns correct value for 1 wins: FAILED\n");
        printf("***** getWinners() returned player1 = %d and player2 = %d *****", players[0], players[1]);
        printf("***** Score for Player1: %d Score for Player2: %d\n *****", scoreFor(0, &G), scoreFor(1, &G));
    }

    fflush(stdout);

    // Print out number of tests passed
    printf("getWinners() PASSED %d out of 5 tests\n\n", testsPassed);
    fflush(stdout);

    return 0;
 }