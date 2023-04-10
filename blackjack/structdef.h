#pragma once

typedef struct cards {
	int card_id;
	int value;
	int suit;
}CARD;

typedef struct {
	CARD playersCards[21];
	int nextCard;
	int currentBetAmount;
	int balance;
}PLAYER;

typedef struct dealer {
	CARD dealersCards[21];
	int nextCard;
}DEALER;