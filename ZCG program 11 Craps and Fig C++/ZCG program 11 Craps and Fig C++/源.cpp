#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum status {CONTINUE,WON,LOST};

int rollDice(void);
int main(void) {
	srand(time(NULL));
	int mypoint;
	int gameStatus;
	int sum = rollDice();
    
    gameStatus=1;
	
	switch (sum) {  //if 和 else的简化版，当括号中的数等于其中的case时，从那个case执行到break，若没有执行default
	case7:
	case11:
		gameStatus = WON;
		break;

	case2:
	case3:
	case12:
		gameStatus = LOST;
		break;

	default:
		gameStatus = CONTINUE;
		mypoint = sum;
		printf("point is %d\n", mypoint);
		break;
	}
	while (CONTINUE == gameStatus) {
		sum = rollDice();

		if (sum == mypoint) {
			gameStatus == WON;
		}
		else {
			if (sum==7) {
				gameStatus == LOST;
			}
		}
	
	getchar();
	if (WON == gameStatus) {
		puts("Player wins");
	}
	else {
		puts("Player loose");
	}
	getchar();
	}
}
int rollDice (void)
{
	int die1 = 1 + (rand() % 6);
	int die2 = 1 + (rand() % 6);
	printf("player rolled %d+%d=%d\n", die1, die2, die1 + die2);
	getchar();
	return die1 + die2;
	getchar();
	getchar();
}