#include <stdio.h>
int main() {
	int x, y, z, p, n ;
	
	z = 1;

	printf("add program \n x=");
	scanf_s("%d",&x);
	printf("(y>x)\n y=");
	scanf_s("%d", &y);
	n = x;
	p = n;
	while (y > x) {
		x = x + z;
		p = p + x;

    }
	printf("the sum add from x to y is %d\n ", p);
	printf("if the answer is ok please input this answer\n");
	scanf_s("1", &p);
	getchar();
	getchar();
	return 0;
}
