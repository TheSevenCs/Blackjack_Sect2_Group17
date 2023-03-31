#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{

	return 0;
}



int hit(int cardsValue)
{
	int randomcard = 0;
	srand(time(0));
	randomcard = (rand() % 13) + 1;
	if(randomcard == 11 || randomcard == 12 || randomcard == 13){
		cardsValue += 10;
	}
	else {
		cardsValue += randomcard;
	}
	
	return cardsValue;

}

bool stand()
{
	char answer;
	printf("Are you sure you want to stand? (y/n)\n");
	scanf_s("%c", answer);

	return false;
}

