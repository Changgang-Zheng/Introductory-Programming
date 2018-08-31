#include <stdio.h>
#include <stdlib.h>  // extra includes!
#include <time.h>
#include <math.h>

void printGame(int values[3][3])
{
	int i, j;
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			if (values[i][j] == 1)
				printf("o ");
			if (values[i][j] == 5)
				printf("x ");
			if (values[i][j] == 0)
				printf(". ");
		}
		printf("\n");
	}
}

void printArray(int values[3][3])
{
	int i, j;
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			printf("%i ", values[i][j]);
		}
		printf("\n");
	}
}

int selectValue(int num, int values[3][3], int playerNo) {
	int row, colum;
	row = 2 - floor((num - 1) / 3);
	colum = (num - 1) % 3;
	if (values[row][colum] == 0) {
		if (playerNo == 1) {
			values[row][colum] = 1;
		}
		if (playerNo == 2) {
			values[row][colum] = 5;
		}
		return 1;
	}
	return 0;
}

int isWin(int values[3][3]) {
	int i, j;
	int num[8];
	for (i = 0; i<8; i++) {
		num[i] = 0;
	}
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			if (i == j) {
				num[0] = num[0] + values[i][j];
			}
			if (2 - i == j) {
				num[1] = num[1] + values[i][j];
			}
			if (j == 0) {
				num[2] = num[2] + values[i][j];
			}
			if (j == 1) {
				num[3] = num[3] + values[i][j];
			}
			if (j == 2) {
				num[4] = num[4] + values[i][j];
			}
			num[5 + i] = num[5 + i] + values[i][j];
		}
	}
	for (i = 0; i<8; i++) {
		if (num[i] == 3) {
			return 1;//value==1 is player
		}
		if (num[i] == 15) {
			return 10;//value==10 is computer
		}
	}
	return 0;
}

int main() {
	int i, j, n;
	int num;
	int values[3][3], valuesC[3][3];
	srand(time(NULL));
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			values[i][j] = 0;
		}
	}
	printGame(values);
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			valuesC[i][j] = (2 - i) * 3 + j + 1;
		}
	}
	printArray(valuesC);
	num = floor(9 * rand() / RAND_MAX) + 1;
	selectValue(num, values, 2);//computer select
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n");
	printGame(values);
	for (n = 0; n<4; n++) {
		printf("Please input your select:");
		scanf_s("%d", &num);
		printf("%i\n", num);
		while (selectValue(num, values, 1) == 0) {
			printf("player select position is occupied\n");
			printf("Please input you select:");
			scanf_s("%d", &num);
			printf("%i\n", num);
		}
		printf("\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n");
		printGame(values);
		if (isWin(values) == 1) {
			printf("human win the game\n");
			getchar();
			getchar();
			return 0;
		}
		num = floor(9 * rand() / RAND_MAX) + 1;
		while (selectValue(num, values, 2) == 0) {
			printf("computer select position is occupied\n");
			num = floor(9 * rand() / RAND_MAX) + 1;
		}
		printf("\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n");
		printGame(values);
		if (isWin(values) == 10) {
			printf("computer win the game\n");
			getchar();
			getchar();
			return 0;
		}
	}
	getchar();
	getchar();
	return 1;
}