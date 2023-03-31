#include "player.h"
#include "dealer.h"


PLAYER* createPlayer() {
	PLAYER* newPlayer = malloc(sizeof(PLAYER));
	newPlayer->playersCards;
	newPlayer->currentBetAmount = 5;
	newPlayer->balance = 200;
	return newPlayer;
}

bool playerTurn(PLAYER* player){
	int choice;
	int bet;

	playerOutput();
	scanf("%d", &choice);

	switch (choice) {
	case(1):
		//hit(player);
		break;
	case(2):
		//return stand(player);
		break;
	case(3):
		printf("How much would you like the bet?: ");
		scanf("%d", &bet);
		//bet(player, bet);
		break;
	default:
		printf("That was not one of the options");
		fflush(stdin);
		break;
	}
	return false;
}

void playerOutput() {
	printf("Enter a number from below:\n\n");
	printf("1) Hit\n");
	printf("2) Stand\n");
	printf("3) Increase your bet\n");
}