#include <stdio.h>
#include <stdlib.h>  // extra includes!
#include <time.h>
#include <math.h>

struct Change {
	int total_pences;
	int pence1;
	int pence2;
	int pence5;
	int pence10;
	int pence20;
	int pence50;
	int pence100;
	int pence200;
};

struct Change getChange(int pences1, int pences2)
{
	struct Change coins;
	int pencesreturn;
	pencesreturn = pences2 - pences1;
	coins.total_pences = pencesreturn;
	coins.pence1 = 0;
	coins.pence2 = 0;
	coins.pence5 = 0;
	coins.pence10 = 0;
	coins.pence20 = 0;
	coins.pence50 = 0;
	coins.pence100 = 0;
	coins.pence200 = 0;

	if (pencesreturn >= 200)
	{
		coins.pence200 = pencesreturn / 200;
		pencesreturn = pencesreturn - coins.pence200 * 200;
	}
	if (pencesreturn >= 100)
	{
		coins.pence100 = pencesreturn / 100;
		pencesreturn = pencesreturn - coins.pence100 * 100;
	}
	if (pencesreturn >= 50)
	{
		coins.pence50 = pencesreturn / 50;
		pencesreturn = pencesreturn - coins.pence50 * 50;
	}
	if (pencesreturn >= 20)
	{
		coins.pence20 = pencesreturn / 20;
		pencesreturn = pencesreturn - coins.pence20 * 20;
	}
	if (pencesreturn >= 10)
	{
		coins.pence10 = pencesreturn / 10;
		pencesreturn = pencesreturn - coins.pence10 * 10;
	}
	if (pencesreturn >= 5)
	{
		coins.pence5 = pencesreturn / 5;
		pencesreturn = pencesreturn - coins.pence5 * 5;
	}
	if (pencesreturn >= 2)
	{
		coins.pence2 = pencesreturn / 2;
		pencesreturn = pencesreturn - coins.pence2 * 2;
	}
	coins.pence1 = pencesreturn;
	return coins;
}

void printChange(struct Change coins)
{
	printf("p200 p100 p50  p20  p10  p5   p2   p1\n");
	printf("%i    %i    %i    %i    %i    %i    %i    %i\n", coins.pence200, coins.pence100, coins.pence50, coins.pence20, coins.pence10, coins.pence5, coins.pence2, coins.pence1);

}


int main() {
	struct Change coins;
	coins = getChange(7, 10);
	printChange(coins);
	coins = getChange(56, 70);
	printChange(coins);
	coins = getChange(124, 200);
	printChange(coins);
	coins = getChange(1232, 2000);
	printChange(coins);

	getchar();
	return 1;
}