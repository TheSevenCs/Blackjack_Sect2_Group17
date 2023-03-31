#include "dealer.h"
#include "actions.h"
#include "Design.h"
DEALER* createDealer() {
	DEALER* newDealer = calloc(1, sizeof(DEALER));
	newDealer->dealersCards[0].card_id = 0;
	newDealer->nextCard = 1;
	return newDealer;
}

bool dealerTurn(DEALER* dealer) {
	bool standStatus = false;
	dHit(dealer);
	if (calculateTotalCardValue(dealer->dealersCards) >= 17) {
		standStatus = true;
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
	char* deal = "d";
	dHit(dealer);
	updateDesign(deal, dealer->dealersCards, dealer->nextCard);
	hit(player);
	hit(player);
	updateDesign("u", player->playersCards, player->nextCard);
}

