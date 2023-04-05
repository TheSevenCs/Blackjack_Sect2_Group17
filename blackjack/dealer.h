#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structdef.h"
#include <time.h>


DEALER* createDealer();
bool dealerTurn(PLAYER*, DEALER*);
void dealCards(PLAYER* player, DEALER* dealer);
int calculateTotalCardValue(CARD[]);
void revealDealerCard(DEALER* dealer);
bool winConditions(PLAYER* player, DEALER* dealer);