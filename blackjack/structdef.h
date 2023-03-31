#pragma once

typedef struct cards {
	int card_id;
	int value;
	int suit;
}CARD;

typedef struct {
	CARD playersCards[10];
	int nextCard;
	int currentBetAmount;
	int balance;
}PLAYER;

typedef struct dealer {
	CARD dealersCards[10];
	int nextCard;
}DEALER;