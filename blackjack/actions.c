#include "actions.h"
#include "dealer.h"
#include "Design.h"

void hit(PLAYER* player)
{
	CARD ArrayOfCards[4][13], randomCard;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++) {
			ArrayOfCards[j][i].card_id = i+1;
			ArrayOfCards[j][i].value = 0;
			ArrayOfCards[j][i].suit = j+1;
		}
	}
	srand(time(0)+ player->nextCard);
	int cardNum = (rand() % 13);
	int suit = (rand() % 4);
	randomCard = ArrayOfCards[suit][cardNum];
	if(randomCard.card_id == 11 || randomCard.card_id == 12 || randomCard.card_id == 13){
		player->playersCards[player->nextCard].value = 10;
	}
	else if (randomCard.card_id == 1) {
		player->playersCards[player->nextCard].value = 11;
	}
	else {
		player->playersCards[player->nextCard].value += randomCard.card_id;
	}
	player->playersCards[player->nextCard].card_id = randomCard.card_id;
	player->playersCards[player->nextCard].suit = randomCard.suit;
	player->nextCard++;
}

void dHit(DEALER* dealer)
{
	CARD ArrayOfCards[4][13], randomCard;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++) {
			ArrayOfCards[j][i].card_id = i + 1;
			ArrayOfCards[j][i].value = 0;
			ArrayOfCards[j][i].suit = j + 1;
		}
	}

	srand(time(0));
	int cardNum = (rand() % 13);
	int suit = (rand() % 4);
	randomCard = ArrayOfCards[suit][cardNum];
	if (randomCard.card_id == 11 || randomCard.card_id == 12 || randomCard.card_id == 13) {
		dealer->dealersCards[dealer->nextCard].value += 10;
	}
	else if (randomCard.card_id == 1) {
		dealer->dealersCards[dealer->nextCard].value = 11;
	}
	else {
		dealer->dealersCards[dealer->nextCard].value += randomCard.card_id;
	}
	dealer->dealersCards[dealer->nextCard].card_id = randomCard.card_id;
	dealer->dealersCards[dealer->nextCard].suit = randomCard.suit;
	dealer->nextCard++;
}

bool stand()
{
	char answer;
	displayBorderHorizontalEmpty();
	displayBorderHorizontalEmpty();
	displayBorderHorizontalEmpty();
	displayBorderHorizontalEmpty();
	displayBorderHorizontalEmpty();
	printf("||||  To confirm, type 'y' to stand:  ||||\n");
	displayBorderHorizontalEmpty();
	displayBorderHorizontalEmpty();
	displayBorderVertical();
	scanf(" %c", &answer);

	if(answer == 'y')
	{
		return false;
	}
	else
	{
		return true;
	}

}

void doubleDown(PLAYER* player)
{
	player->balance -= player->currentBetAmount;

	player->currentBetAmount *= 2;

	hit(player);

}

void bet(PLAYER* player, int userCash)
{
	while (true) {
		while (userCash <= 0)
		{
			printf("\nIncorrect Value\n");
			printf("Please enter a new bet: ");
			scanf("%d", &userCash);
		}

		while (userCash > player->balance)
		{
			printf("\nInsufficient Funds\n");
			printf("Please enter a new bet: ");
			scanf("%d", &userCash);
		}
		printf("\n");
		if (userCash <= player->balance && userCash > 0) {
			break;
		}
	}
	
	player->balance -= userCash;

	player->currentBetAmount = userCash;

}