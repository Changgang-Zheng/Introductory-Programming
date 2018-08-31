#include<stdio.h>
#include <stdlib.h>  // extra includes!
#include <time.h>
#include <math.h>

float getRand() {
	return rand() / (RAND_MAX + 1.0);
}

int compare(int p, int q) {
	if (p < q) {
		printf("\nyour answer is too high\n");
	}
	else {
		printf("\nyour answer is too low\n");
	}
	return 0;
}

int numberwrong(int a) {
	int i = 0;
	int ran = getRand();
	while (ran < (float)i / a) {
		i = i + 1;
	}
	return i;
}

int number(int x) {
	float sizeF, sizeFP;
	int size;
	sizeFP = getRand() * 20 + 1;
	sizeF = floor(sizeFP);
	return sizeF;
}

int game(int m) {
	int choose, g[5], r, s, t, l;
	int value = number(32);
	r = 0;
	s = 5;
	t = r + 1;
	choose = 0;
	printf("gess it(your %dth choice)", t);
	scanf_s("%d", &g[r]);
	if (g[r] == value) {
		s = s - 1;
		printf("\ncongratulations,your answer is right and the number is %d", value);
		printf("\nyou win at %dth", t);
		return 0;
	}
	else {
		compare(value, g[r]);
		r = r + 1;
		t = r + 1;
		s = s - 1;
		printf("your answer is wrong and guess again and you have %d chance left", s);
		printf("\ngess it(your %dth choice)", t);
		scanf_s("%d", &g[r]);
		if (g[r] == value) {
			printf("\ncongratulations,your answer is right and the number is %d", value);
			printf("\nyou win at %dth", t);
		}
		else {
			compare(value, g[r]);
			s = s - 1;
			r = r + 1;
			t = r + 1;
			printf("your answer is wrong and guess again and you have %d chance left", s);
			printf("\ngess it(your %dth choice)", t);
			scanf_s("%d", &g[r]);
			if (g[r] == value) {
				printf("\ncongratulations,your answer is right and the number is %d", value);
				printf("\nyou win at %dth", t);
			}
			else {
				compare(value, g[r]);
				s = s - 1;
				r = r + 1;
				t = r + 1;
				printf("your answer is wrong and guess again and you have %d chance left", s);
				printf("\ngess it(your %dth choice)", t);
				scanf_s("%d", &g[r]);
				if (g[r] == value) {
					printf("\ncongratulations,your answer is right and the number is %d", value);
					printf("\nyou win at %dth", t);
				}
				else {
					compare(value, g[r]);
					s = s - 1;
					r = r + 1;
					t = r + 1;
					printf("your answer is wrong and guess again and you have %d chance left", s);
					printf("\ngess it(your %dth choice)", t);
					scanf_s("%d", &g[r]);
					if (g[r] == value) {
						printf("\ncongratulations,your answer is right and the number is %d", value);
						printf("\nyou win at %dth", t);
					}
					else {
						compare(value, g[r]);
						s = s - 1;
						r = r + 1;
						t = r + 1;
						printf("your answer is wrong and guess again and you have %d chance left\n", s);
						printf("you lose");
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	srand(time(NULL)); // init random
	getRand(); // kick-start the random numbers

    int value = 0;
	int choose, g[5], r, s, t, l;

	r = 0;
	s = 5;
	t = r + 1;
	choose = 0;
	

	l = game(1);

	getchar();
	getchar();
}