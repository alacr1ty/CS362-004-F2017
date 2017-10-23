
// 1- Write unit tests for four functions (not card implementations, and not cardEffect)
// in dominion.c “the refactored code you created for assignment-2”. Check these tests in
// as unittest1.c,unittest2.c, unittest3.c, and unittest4.c. At least two of these
// functions should be more than 5 lines of code. (20 points)

// Testing BuyCard()

// unittest1: unittest1.c dominion.o rngs.o
// 	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define KINGDOM_SIZE 10


int main () {

	// Initialize random seed
	srand(time(NULL)); 

	// gameState definition
	// struct gameState {
	//   int numPlayers; //number of players
	//   int supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
	//   int embargoTokens[treasure_map+1];
	//   int outpostPlayed;
	//   int outpostTurn;
	//   int whoseTurn;
	//   int phase;
	//   int numActions; /* Starts at 1 each turn */
	//   int coins; /* Use as you see fit! */
	//   int numBuys; /* Starts at 1 each turn */
	//   int hand[MAX_PLAYERS][MAX_HAND];
	//   int handCount[MAX_PLAYERS];
	//   int deck[MAX_PLAYERS][MAX_DECK];
	//   int deckCount[MAX_PLAYERS];
	//   int discard[MAX_PLAYERS][MAX_DECK];
	//   int discardCount[MAX_PLAYERS];
	//   int playedCards[MAX_DECK];
	//   int playedCardCount;
	// };

	// Initialize game state and associated variables
	struct gameState state;
	int playerNum = 2;
	int cards[treasure_map-6];
	int lenCards = sizeof(cards)/sizeof(int);
	int kingdom[KINGDOM_SIZE];
	int seed = rand()%1000000;
	int i, c, pos;

	// Initalize a random kingdom
	// create an array of all valid potential kingdom cards
	for (i = adventurer; i < treasure_map; ++i)
		cards[i-7] = CARD[i];

	// For each card in the kingdom...
	for (i = 0; i < KINGDOM_SIZE; ++i){
		// choose a random card, excluding the first 7 cards
		pos = rand()%lenCards
		// add it to the kindgom
		kingdom[i] = cards[pos];
		// remove it from the choices
		for (c = pos ; c < lenCards ; c++)
        	cards[c] = cards[c+1];
	}

	// For n number of possibilities

		// Clear the gamestate

		// Initialize a new game

		// If needed, copy the current gamestate

		// Call the function to test

		// Perform the method to determine the correct result

		// Assert that the function's return value matches the correct result





	return 0;

}
