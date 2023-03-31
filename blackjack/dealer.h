#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "player.h"
#include "cards.h"
typedef struct dealer {
	CARD dealersCards[10];
}DEALER;

DEALER* createDealer();
bool dealerTurn(DEALER*);
int calculateTotalCardValue(CARD[]);