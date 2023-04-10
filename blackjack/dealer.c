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

	if (calculateTotalCardValue(dealer->dealersCards, dealer->nextCard) >= 17) {
		standStatus = false;
	}
	else {
		dHit(dealer);
	}
	return standStatus;
}



int calculateTotalCardValue(CARD list[], int index) {
	int total = 0, aceCount = 0;
	for(int i = 0; i < index; i++){
		if (list[i].value == 11) {
			aceCount++;
		}
		total += list[i].value;
	}
	
	for (int j = index; j > 0; j--) {
		if (total > 21 && aceCount > 0) {
			if (changeAce(list[j])) {
				list[j].value >>= 3;
				total -= 10;
				aceCount--;
			}
		}
		else { break; }
	}
	return total;
}

bool changeAce(CARD card) {
	if (card.value == 11){
		return true;
	}
	return false;
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
	int pValue = calculateTotalCardValue(player->playersCards, player->nextCard), dValue = calculateTotalCardValue(dealer->dealersCards, dealer->nextCard);
	char choice;
	FILE* fPtr;
	Sleep(1500);
	printf("\n");
	if (pValue > 21) {
		displayBustScreen();
	}
	else if (dValue > 21) {
		player->balance += player->currentBetAmount * 2;
		displayDealerBustScreen();
	}
	else if (dValue == pValue) {
		player->balance += player->currentBetAmount;
		displayTieScreen();
	}
	else if (pValue == 21) {
		player->balance += player->currentBetAmount * 2;
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
	

	printf("\n\Would you like to play again? (y/n)\n");
	scanf(" %c", &choice);
	if (choice == 'y') {
		return true;
	}
	else {
		return false;
	}
}