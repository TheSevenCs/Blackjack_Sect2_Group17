#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structdef.h"



PLAYER* createPlayer();
bool playerTurn(PLAYER*, DEALER*);
void playerOutput();