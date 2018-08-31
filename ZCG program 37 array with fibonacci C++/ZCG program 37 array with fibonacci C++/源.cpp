#include <stdio.h> 
void fibonacci(int arr[], int size);
void changeArray(int arr[], int size);

int main(void)
{
	printf("how many number do you want?");
	int array[50], number;
	scanf_s("%d", &number, 1);
	fibonacci(array,number);
	printf("how many number do you want?");
	scanf_s("%d", &number, 1);
	fibonacci(array, number);
	printf("how many number do you want?");
	scanf_s("%d", &number, 1);
	fibonacci(array, number);
	getchar();
	getchar();
}

void fibonacci(int arr[], int size) {
	int i;
	arr[0] = 0;
	arr[1] = 1;
	for (i = 2; i<size; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	for (i = 0; i<size; i++) {
		int p = i + 1;
		printf("the %ith fibonacci is %i\n ", p, arr[i]);
	}
}
void changeArray(int arr[], int size) {
	int i;
	for (i = 0; i<size; i++) {
		arr[i] = arr[i] * arr[i] + 3;
	}
}

