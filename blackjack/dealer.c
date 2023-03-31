#include "dealer.h"

DEALER* createDealer() {
	DEALER* newDealer = calloc(1, sizeof(DEALER));
	return newDealer;
}

bool dealerTurn(struct dealer* dealer) {
	bool standStatus = false;
	//hit function
	if (calculateTotalCardValue(dealer->dealersCards) >= 17){
		standStatus = true;
	}
	return standStatus;
}



int calculateTotalCardValue(CARD list[]) {
	int i = 0, total = 0;
	while (list[i].value != NULL) {
		total += list[i].value;
		i++;
	}
}

void dealCards(DEALER* dealer, PLAYER* player) {
	//hit(dealer);
	//hit(player);
	//hit(player);
}

