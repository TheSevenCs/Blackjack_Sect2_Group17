#include "player.h"
#include "dealer.h"
#include "actions.h"
#include "Design.h"
#include "dealer.h"

PLAYER* createPlayer() {
	PLAYER* newPlayer = calloc(1, sizeof(PLAYER));
	newPlayer->nextCard = 0;
	newPlayer->balance = 500;
	return newPlayer;
}

bool playerTurn(PLAYER* player, DEALER* dealer){
	int choice;
	playerOutput();
	scanf("%d", &choice);
	printf("%s", generateTable());
	updateDesign("d", dealer->dealersCards, dealer->nextCard);
	switch (choice) {
	case(1):
		hit(player);
		break;
	case(2):

		updateDesign("u", player->playersCards, player->nextCard);
		return stand();
		break;
	default:
		printf("That was not one of the options");
		fflush(stdin);
		break;
	}
	updateDesign("u", player->playersCards, player->nextCard);
	return true;
}

void playerOutput() {
	printf("\nEnter a number from below:\n\n");
	printf("1) Hit\n");
	printf("2) Stand\n");
}