
#include <stdio.h>
void convertBin(int byte) {
	int count = 8;
	int mask = 1 << (count - 1);
	while (count--) {
		if (byte&mask) printf("1"); else printf("0");
		byte= byte<<1;
	}
	printf("\n");
}
int main() {
	int i = 55, j = 27; convertBin(i); convertBin(j); convertBin(i^j); 
	getchar();
}