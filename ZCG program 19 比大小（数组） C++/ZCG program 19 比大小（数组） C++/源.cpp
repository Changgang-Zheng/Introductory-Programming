#include <stdio.h>
int main(void) {
	float number[1000];
	int scanfinput;
	int measure,realmeasure;
	float board;
	int pointer1=0;
	int pointer2=1;
	int m,n;

	printf("%s","input number measure \n");
	puts("measure<=1000");
	scanf_s("%d", &measure, 1);

	for (n = 1; n <= measure; n++) {
		m = n - 1;
		printf("\n input number %d \n", n);
		scanf_s("%f", &number[m], 1);
	}
	realmeasure = measure - 1;
	for (pointer1 = 0; pointer1 <= realmeasure; pointer1++) {
		for (pointer2 = pointer1+1; pointer2 <= realmeasure; pointer2++) {
			if (number[pointer1] > number[pointer2]) {
				board = number[pointer1];
				number[pointer1] = number[pointer2];
				number[pointer2] = board;
			}
		}
	}
	getchar();
	getchar();
}