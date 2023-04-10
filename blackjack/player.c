#include "player.h"
#include "dealer.h"
#include "actions.h"
#include "Design.h"
#include "dealer.h"
#define	STARTING_BALANCE	500

PLAYER* createPlayer() {
	PLAYER* newPlayer = calloc(1, sizeof(PLAYER));
	newPlayer->nextCard = 0;
	newPlayer->balance = STARTING_BALANCE;
	return newPlayer;
}

bool playerTurn(PLAYER* player, DEALER* dealer){
	int choice;
	playerOutput();
	scanf("%d", &choice);
	printf("%s", generateTable());
	
	("d", dealer->dealersCards, dealer->nextCard);
	switch (choice) {
	case(1):
		hit(player);
		break;
	case(2):

		updateScreen(player, dealer);
		return stand();
		break;
	default:
		printf("That was not one of the options");
		fflush(stdin);
		break;
	}
	updateScreen(player, dealer);
	return true;
}

void playerOutput() {
	displayBorderHorizontalEmpty();
	printf("||||    Enter a number from below:    ||||\n");
	displayBorderHorizontalEmpty();
	printf("||||             1) Hit               ||||\n");
	printf("||||             2) Stand             ||||\n");
	displayBorderHorizontalEmpty();
	displayBorderVertical();
}