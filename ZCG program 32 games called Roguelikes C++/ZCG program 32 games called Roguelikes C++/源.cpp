#include <stdio.h>
int drawRoom(int wide,int high,int horizontal,int vertical) {
	wide = wide + 2;
	high = high = +2;
	char array[high][wide], m;
	for (int i = 0; i <= high-1; i++) {
		for (int j = 0; j <= wide-1; j++) {
			array[i][j] = 0;
		}
	}
	for (int n = 1; n <= wide; n++) {
		m = 0;
		array[m][n] = '-';
	}
	for (int n = 1; n <= wide; n++) {
		m = 15;
		array[m][n] = '-';
	}
	for (int n = 1; n <= wide; n++) {
		m = 0;
		array[n][m] = '|';
	}
	for (int n = 1; n <= wide; n++) {
		m = 9;
		array[n][m] = '-';
	}
	for (int i = 1; i <= high-2; i++) {
		for (int j = 1; j <= wide-2; j++) {
			array[i][j] = '.';
		}
	}
	horizontal = horizontal + 1;
	vertical = vertical + 1;
	array[horizontal][vertical] = '@';
	array[0][0] = '+';
	array[9][0] = '+';
	array[0][15] = '+';
	array[9][15] = '+';
	for (int i = 0; i <= high - 1; i++) {
		for (int j = 0; j <= wide - 1; j++) {
			printf("%c",array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int main() {
	drawRoom(2, 2, 0, 1);
	drawRoom(5, 3, 1, 2);
	drawRoom(14, 8, 8, 5);
	getchar();
	return 0;
}