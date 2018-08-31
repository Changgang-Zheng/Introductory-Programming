#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(0));
	int a = 1 + rand() % 11;
	printf("random=%d\n", a);
	getchar();
}