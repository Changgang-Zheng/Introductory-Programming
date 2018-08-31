#include <stdio.h>
#include <stdlib.h>  // extra includes!
#include <time.h>
#include <math.h>

int winornot(int values[3][3], int l) {
	int m = 0;
	if (((values[0][0] == values[0][1]) && (values[0][0] == values[0][2]) && (values[0][0] != 0)) ||
		((values[1][0] == values[1][1]) && (values[1][0] == values[1][2]) && (values[1][0] != 0)) ||
		((values[2][0] == values[2][1]) && (values[2][0] == values[2][2]) && (values[2][0] != 0)) ||
		((values[0][0] == values[1][0]) && (values[0][0] == values[2][0]) && (values[0][0] != 0)) ||
		((values[0][1] == values[1][1]) && (values[0][1] == values[2][1]) && (values[0][1] != 0)) ||
		((values[0][2] == values[1][2]) && (values[0][2] == values[2][2]) && (values[0][2] != 0)) ||
		((values[0][0] == values[1][1]) && (values[0][0] == values[2][2]) && (values[0][0] != 0)) ||
		((values[0][2] == values[1][1]) && (values[0][2] == values[2][0]) && (values[0][2] != 0))) {
		if (l == 0) {
			printf("the human player win ");
			getchar(); 
			getchar();
			getchar();
			getchar();
			return 1;
		}
		if (l == 1) {
			printf("the computer win ");
			getchar();
			getchar();
			getchar();
			getchar();
			return 1;
		}
	}
	return 0;
}

void printGame(int values[3][3])
{
	int i, j;
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			if (values[i][j] == 1)
				printf("o ");
			if (values[i][j] == 2)
				printf("X ");
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

int selectValue(int values[3][3], int choose, int l) {
	int row, colum;
	int num;
	if (l == 0) {
		printf("Please input you commend:");
		scanf_s("%d", &num);
	}
	if (l == 1) {
		printf("Computer input commend:");
		num = floor(9 * rand() / RAND_MAX) + 1;
	}
	printf("%i\n", num);
	if (choose == 1) {
		row = floor(num / 3);
		colum = num - row * 3;
	}
	if (choose == 2) {
		row = floor(num / 3.1);
		colum = num - row * 3 - 1;
	}
	if (choose == 3) {
		row = 2 - floor((num - 1) / 3);
		colum = (num - 1) % 3;
	}
	if (values[row][colum] != 0) {
		return 0;
	}
	if (l == 0) {
		values[row][colum] = 1;
	}
	if (l == 1) {
		values[row][colum] = 2;
	}
	return 1;
}

int main() {
	srand(time(NULL));
	int i, j, z, choose, num;
	int n, values[3][3], valuesC[3][3];
	for (i = 0; i<3; i++) {
		for (j = 0; j<3; j++) {
			values[i][j] = 0;
		}
	}
	// sample
	z = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			valuesC[i][j] = i + j + z;
		}
		z = z + 2;
	}
	printArray(valuesC);
	printf("keeyboard sample 1\n");
	z = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			valuesC[i][j] = i + j + 1 + z;
		}
		z = z + 2;
	}
	printArray(valuesC);
	printf("keeyboard sample 2\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			valuesC[i][j] = (2 - i) * 3 + j + 1;
		}
	}
	printArray(valuesC);
	printf("keeyboard sample 3\n");
	//sample
	choose = 0;
	printf("\nplease choose your keyboard:");
	scanf_s("%d", &choose);
	printGame(values);
	if (choose == 1) {
		z = 0;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				valuesC[i][j] = i + j + z;
			}
			z = z + 2;
		}
	}
	z = 0;
	if (choose == 2) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				valuesC[i][j] = i + j + 1 + z;
			}
			z = z + 2;
		}
	}
	if (choose == 3) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				valuesC[i][j] = (2 - i) * 3 + j + 1;
			}
		}
	}
	printArray(valuesC);
	int l = 0;
	for (n = 0; n < 9; n++) {
		l = l*l;
		if (l == 0) {
			printf("human player\n");
		}
		if (l == 1) {
			printf("computer player\n");
		}
		while (selectValue(values, choose, l) == 0) {
			printf("your position is occupied\n");
		}
		printf("\n\n");
		printf("\n\n");
		printf("\n\n");
		printGame(values);
		printArray(valuesC);
		if (winornot(values, l)) {
	    return 0;
		}
		
		l = l - 1;
	}
	int v = winornot(values, l);
	if (n == 9 && v != 1) {
		printf("if you not win now you lose....");
	}
	printf("if you not win now you lose....");
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
}