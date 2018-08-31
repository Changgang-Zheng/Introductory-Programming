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
				printf("¥ ");
			if (values[i][j] == 2)
				printf("# ");
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

int selectValue(int values[3][3], int choose) {
	int row, colum;
	int num;
	printf("Please input you commend:");
	scanf_s("%d", &num);
	printf("%i\n", num);
	if (choose < 2) {
		row = floor(num / 3);
		colum = num - row * 3;
	}
	if (1 < choose < 3) {
		row = floor(num / 3.1) ;
		colum = num - row * 3 - 1;
	}
	if (choose > 2) {
	row = 2 - floor((num - 1) / 3);
	colum = (num - 1) % 3;
}
	if (values[row][colum] != 1) {
		values[row][colum] = 1;
		return 1;
	}
	return 0;
}

int main() {
	int i, j, z, choose;
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
	if(choose <2) {
		z = 0;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				valuesC[i][j] = i + j + z;
			}
			z = z + 2;
		}	
	}
	z = 0;
	if (1<choose <3) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				valuesC[i][j] = i + j + 1 + z;
			}
			z = z + 2;
		}
	}
	if (choose >2) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				valuesC[i][j] = (2 - i) * 3 + j + 1;
			}
		}
	}
	printArray(valuesC);
	for (n = 0; n < 9; n++) {
		while (selectValue(values,choose) == 0) {
			printf("your position is occupied\n");
		}
		printf("\n\n");
		printf("\n\n");
		printf("\n\n");
		printGame(values);
		printArray(valuesC);
	}
	getchar();
}