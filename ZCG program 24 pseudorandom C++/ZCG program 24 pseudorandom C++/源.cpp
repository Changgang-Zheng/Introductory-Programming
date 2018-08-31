#include <stdio.h>
#include <stdlib.h>  // extra includes!
#include <time.h>
#include <math.h>


float getRand() {
	return rand() / (RAND_MAX + 1.0);
}

int rollDie(int x) {
	float sizeF, sizeFP;
	int size;
	if (x == 20) {
		sizeFP = getRand() * 20 + 1;
		sizeF = floor(sizeFP);
	}
	else {
		sizeFP = getRand() * 6 + 1;
		sizeF = floor(sizeFP);
	}
	return sizeF;
}
int main() {
	srand(time(NULL)); // init random
	getRand(); // kick-start the random numbers
	int value = 0;
	value = rollDie(6);
	printf("6-sided die: %i\n", value);
	value = rollDie(20);
	printf("20-sided die: %i\n", value);
	getchar();
}
