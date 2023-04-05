#define _CRT_SECURE_NO_WARNINGS
#include "dealer.h"
#include "actions.h"
#include "Design.h"
#include <Windows.h>

DEALER* createDealer() {
	DEALER* newDealer = calloc(1, sizeof(DEALER));
	newDealer->dealersCards[0].card_id = 0;
	newDealer->nextCard = 1;
	return newDealer;
}

bool dealerTurn(PLAYER* player, DEALER* dealer) {
	bool standStatus = true;
	printf("%s", generateTable());
	updateScreen(player, dealer);

	if (calculateTotalCardValue(dealer->dealersCards) >= 17) {
		standStatus = false;
	}
	else {
		dHit(dealer);
	}
	return standStatus;
}



int calculateTotalCardValue(CARD list[]) {
	int i = 0, total = 0;
	while (list[i].value != 0) {
		total += list[i].value;
		i++;
	}
	return total;
}

void dealCards(PLAYER* player, DEALER* dealer) {
	dHit(dealer);
	hit(player);
	hit(player);
}

void revealDealerCard(DEALER* dealer) {
	int saveIndex = dealer->nextCard;
	dealer->nextCard = 0;
	dHit(dealer);
	dealer->nextCard = saveIndex;
}

bool winConditions(PLAYER* player, DEALER* dealer) {
	int pValue = calculateTotalCardValue(player->playersCards), dValue = calculateTotalCardValue(dealer->dealersCards);
	char choice;
	Sleep(1500);
	printf("\n");
	if (pValue > 21) {
		displayBustScreen();
	}
	else if (dValue > 21) {
		displayDealerBustScreen();
	}
	else if (pValue == 21) {
		displayBlackJackScreen();
	}
	else if (dValue == 21) {
		displayDealerBlackJackScreen();
	}
	else if (pValue > dValue) {
		player->balance += player->currentBetAmount * 2;
		displayWinScreen();
	}
	else if (dValue > pValue) {
		displayLoseScreen();
	}
	else if (dValue == pValue) {
		player->balance += player->currentBetAmount;
		displayTieScreen();
	}
	printf("\n\nType 'y' to play again\n");
	scanf(" %c", &choice);
	if (choice == 'y') {
		return true;
	}
	else {
		return false;
	}
}