#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structdef.h"

void dHit(DEALER* dealer);
void hit(PLAYER* player);
bool stand();
void doubleDown(PLAYER* player);
void bet(PLAYER* player, int betAmount);
