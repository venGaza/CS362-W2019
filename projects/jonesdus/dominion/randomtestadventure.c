#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
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

void randomTestGenerator () {
    
}

int main () {


    return 0;
}