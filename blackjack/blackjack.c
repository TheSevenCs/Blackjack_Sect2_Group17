#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "actions.h"
#include "dealer.h"
#include "Design.h"
#include "player.h"
#include "structdef.h"
#include <windows.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int color = 0x07;
	FILE* fPtr, *write;
	if (argc < 2) {
		printf("Not enough arguments in command line");
		exit(0);
	}
	else if (argc > 2) {
		printf("Too many arguments in command line");
		exit(0);
	}
	bool playAgain = true;
	while (playAgain) {
		DEALER* dealer = createDealer();
		PLAYER* player = createPlayer();
		
		if (fPtr = fopen(argv[1], "r")) {
			fscanf(fPtr, "%d %d", &player->balance, &color);
			setColor(color);
		}
		fclose(fPtr);
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
				color = customizeDesign();
				if (write = fopen(argv[1], "w")) {
					fprintf(write, "%d %d", player->balance, color);
					fclose(write);
				}
				else {
					perror("Error: Could not write to file");
				}
			}
			play = NULL;
		}

		

		int betAmount;
		char doDoubleDown;
		bool playerStatus = true, dealerStatus = true;
		initializeDesign();
		displayBalance(player);
		displayBorderVertical();
		printf("\nEnter your bet amount:\n");
		scanf("%d", &betAmount);
		bet(player, betAmount);

		system("cls");
		dealCards(player, dealer);
		updateScreen(player, dealer);
		if (player->balance >= player->currentBetAmount) {
			
			displayBorderHorizontalEmpty();
			printf("||||        Double Down? (y/n):       ||||\n");
			displayBorderHorizontalEmpty();
			displayBorderHorizontalEmpty();
			displayBorderHorizontalEmpty();
			displayBorderHorizontalEmpty();
			displayBorderVertical();
			scanf(" %c", &doDoubleDown);
			if (doDoubleDown == 'y') {
				doubleDown(player);
				playerStatus = false;
				if (calculateTotalCardValue(player, player->nextCard) >= 21) {
					dealerStatus = false;
				}
			}

			else {
				updateScreen(player, dealer);
				fflush(stdin);
			}
		}
		while (playerStatus) {
			playerStatus = playerTurn(player, dealer);
			if (calculateTotalCardValue(player->playersCards, player->nextCard) >= 21) {
				playerStatus = false;
				dealerStatus = false;
			}
		}

		revealDealerCard(dealer);
		updateScreen(player, dealer);
		displayBorderHorizontalEmpty();
		displayBorderHorizontalEmpty();
		displayBorderHorizontalEmpty();
		displayBorderHorizontalEmpty();
		displayBorderVertical();
		while (dealerStatus) {
			dealerStatus = dealerTurn(player, dealer);
			displayBorderHorizontalEmpty();
			displayBorderHorizontalEmpty();
			displayBorderHorizontalEmpty();
			displayBorderHorizontalEmpty();
			displayBorderVertical();

			Sleep(2500);
			updateScreen(player, dealer);
			displayBorderHorizontalEmpty();
			displayBorderHorizontalEmpty();
			displayBorderHorizontalEmpty();
			displayBorderHorizontalEmpty();
			displayBorderVertical();
			if (calculateTotalCardValue(dealer->dealersCards, dealer->nextCard) >= 21) {
				dealerStatus = false;
			}
		}
		playAgain = winConditions(player, dealer);
		
		if (write = fopen(argv[1], "w")) {
			fprintf(write, "%d %d", player->balance, color);
			fclose(write);
		}
		else {
			perror("Error: Couldn't create file");
		}
		free(dealer);
		free(player);
	}
	
}

