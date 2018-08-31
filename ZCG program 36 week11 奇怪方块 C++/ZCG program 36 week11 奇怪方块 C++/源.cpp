#include<stdio.h>

int horizontaledge(int a);

int without_player(int a);

int with_player(int a, int b);

int drawRoom(int a, int b, int c, int d);

int main() {
	drawRoom(2, 2, 0, 1);
	drawRoom(5, 3, 1, 2);
	drawRoom(14, 8, 8, 5);
	getchar();
	return 0;
}

int horizontaledge(int a) {
	printf("+");
	for (a; a > 0; a--) {
		printf("-");
	}
	printf("+\n");
	return 0;
}

int without_player(int a) {
	printf("|");
	for (a; a > 0; a--) {
		printf(".");
	}
	printf("|\n");
	return 0;
}

int with_player(int a, int b) {
	int i;
	printf("|");
	for (i = 1; i <= b - 1; i++) {
		printf(".");
	}
	printf("@");
	for (i = b + 1; i <= a; i++) {
		printf(".");
	}
	printf("|\n");
	return 0;
}

int drawRoom(int a, int b, int c, int d) {
	int i;
	c += 1;//c=c+1
	d += 1;//d=d+1
	horizontaledge(a);
	for (i = 1; i <= d - 1; i++) {
		without_player(a);
	}
	with_player(a, c);
	for (i = d + 1; i <= b; i++) {
		without_player(a);
	}
	horizontaledge(a);
	return 0;
}