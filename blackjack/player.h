#pragma once
#include <stdio.h>
#include "cards.h"
#include <stdlib.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct player {
	CARD playersCards[10];
	int currentBetAmount;
	int balance;
}PLAYER;

PLAYER* createPlayer();
bool playerTurn(PLAYER*);
void playerOutput();