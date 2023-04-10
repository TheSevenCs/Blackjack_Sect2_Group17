#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "actions.h"
#include "dealer.h"
#include "Design.h"
#include "player.h"
#include "structdef.h"
#include <stdlib.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	customizeDesign();
	
	DEALER* dealer = createDealer();
	PLAYER* player = createPlayer();

	int betAmount;
	char doDoubleDown;
	bool playerStatus = true, dealerStatus = true;
	initializeDesign();
	printf("Enter your bet amount:\n");
	scanf("%d", &betAmount);
	bet(player, betAmount);
	system("cls");

	printf("%s", generateTable());
	dealCards(player, dealer);
	updateBetDisplay(player->currentBetAmount);

	printf("\nType 'y' to double down?: \n");
	scanf("  %c", &doDoubleDown);
	if (doDoubleDown == 'y') {
		doubleDown(player);
		updateBetDisplay(player->currentBetAmount);
	}

	else {
		fflush(stdin);
	}
	system("cls");
	printf("%s", generateTable());
	updateDesign("d", dealer->dealersCards, dealer->nextCard);
	updateDesign("u", player->playersCards, player->nextCard);
	updateBetDisplay(player->currentBetAmount);

	while (playerStatus) {
		
		playerStatus = playerTurn(player, dealer);
		system("cls");
		if (calculateTotalCardValue(player->playersCards) > 21) {
			printf("You busted! ");
			playerStatus = false;
		}
	}
}