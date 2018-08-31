#include <stdio.h>
int main(void)
{
	unsigned int x, y, z, total;
	total = 0;
	printf("input the lowest number:\n");
	scanf_s("%d", &x);
	printf("input the highest number:\n\n");
	scanf_s("%d", &y);

	while (x <= y) {
		z = x*x;
		printf("%d\n", z);
		total += z;
		++x;
    }
	printf("total is %d\n", total);
	getchar();
	getchar();
 }