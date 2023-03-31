#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structdef.h"


DEALER* createDealer();
bool dealerTurn(DEALER*);
void dealCards(PLAYER* player, DEALER* dealer);
int calculateTotalCardValue(CARD[]);