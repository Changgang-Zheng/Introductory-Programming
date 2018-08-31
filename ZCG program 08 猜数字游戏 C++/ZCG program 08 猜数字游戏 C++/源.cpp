#include <stdio.h>
int main() {
	int x, y, z;
	printf("I have a number betwen 1 to 1000.\n can you gass my number ? \n");
	x = 869;
	printf(" please type your gess.\n");
	scanf_s("d%",&y,1);
	while (x>y) {
		printf(" your answer is too low......\n please type your gess again.\n");
	    scanf_s("%d",&y,1);
		getchar();
	}
	while (x<y) {
		printf("your answer is too high......\n please type your gess again\n");
		scanf_s("%d",y,1);
		getchar();
	}
    if (x=y) {
		printf("\n your answer is right !!! \n congratulations to you !!!");
	}
	getchar();
 }