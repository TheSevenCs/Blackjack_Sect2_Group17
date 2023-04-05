#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "actions.h"
#include "dealer.h"
#include "Design.h"
#include "player.h"
#include "structdef.h"
#include <windows.h>
#include <stdlib.h>

int main()
{
	bool playAgain = true;
	while (playAgain) {
		int play;
		while (true) {
			displayWelcomeScreen();
			fflush(stdin);
			scanf("%d", &play);
			system("cls");
			if (play == 1) {
				break;
			}
			else if (play == 2) {
				customizeDesign();
			}
			play = NULL;
		}

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

		dealCards(player, dealer);
		updateScreen(player, dealer);

		printf("\nDouble Down? (y/n): \n");
		scanf(" %c", &doDoubleDown);
		if (doDoubleDown == 'y') {
			if (player->currentBetAmount * 2 > player->balance)
			{
				printf("Insufficient Funds\n");
			}
			else {
				doubleDown(player);
				updateBetDisplay(player->currentBetAmount);
				playerStatus = false;
			}
			
		}

		else {
			fflush(stdin);
		}
		updateScreen(player, dealer);

		while (playerStatus) {
			playerStatus = playerTurn(player, dealer);
			if (calculateTotalCardValue(player->playersCards) >= 21) {
				playerStatus = false;
				dealerStatus = false;
			}
		}

		revealDealerCard(dealer);
		updateScreen(player, dealer);

		while (dealerStatus) {
			dealerStatus = dealerTurn(player, dealer);
			Sleep(2500);
			updateScreen(player, dealer);
			if (calculateTotalCardValue(dealer->dealersCards) >= 21) {
				dealerStatus = false;
			}
		}
		playAgain = winConditions(player, dealer);
	}
}

