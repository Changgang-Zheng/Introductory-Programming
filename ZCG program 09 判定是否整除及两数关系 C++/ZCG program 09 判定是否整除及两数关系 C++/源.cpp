#include<stdio.h>
int main(void) {
	printf("enter two intenger and i will tell you\n");
	printf("the relationships they satisfy:");

	int num1;
	int num2;
	int z;

	scanf_s("%d %d", &num1, &num2,2);
	
	if (num1 == num2) {
		printf("%d is equal to %d \n ", num1 , num2 );
	}
	if (num1 != num2) {
		printf("%d is not equal to %d \n " ,num1 , num2 );

	}
	if (num1 < num2) {
		printf("%d is less than %d \n ",num1 ,num2);

	}
	if (num1 > num2) {
		printf("%d is greater than %d \n " ,num1 , num2);

	}
	if (num1 <= num2) {
		printf("%d is less than or equal to %d \n ",num1 , num2);

	}

	if (num1 >= num2) {
		printf("%d is greater than or equal to %d \n",num1 , num2);
		

	}
	 
	getchar();
	getchar();
	
 }