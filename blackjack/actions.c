#include "actions.h"


void hit(PLAYER* player)
{
	int randomcard = 0, suit;
	srand(time(0)+ player->nextCard);
	randomcard = (rand() % 13) + 1;
	if(randomcard == 11 || randomcard == 12 || randomcard == 13){
		player->playersCards[player->nextCard].value += 10;
	}
	else {
		player->playersCards[player->nextCard].value += randomcard;
	}
	player->playersCards[player->nextCard].card_id = randomcard;
	player->playersCards[player->nextCard].suit = (rand() % 4) + 1;
	player->nextCard++;
}

void dHit(DEALER* dealer)
{
	int randomcard = 0;
	srand(time(0));
	randomcard = (rand() % 13) + 1;
	if (randomcard == 11 || randomcard == 12 || randomcard == 13) {
		dealer->dealersCards[dealer->nextCard].value += 10;
	}
	else {
		dealer->dealersCards[dealer->nextCard].value += randomcard;
	}
	dealer->dealersCards[dealer->nextCard].card_id = randomcard;
	dealer->nextCard++;
}

bool stand()
{
	char answer;
	printf("To confirm, type 'y' to stand:\n");
	scanf("%c", &answer);

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

}

void bet(PLAYER* player, int userCash)
{
	player->balance -= userCash;

	player->currentBetAmount = userCash;

}
