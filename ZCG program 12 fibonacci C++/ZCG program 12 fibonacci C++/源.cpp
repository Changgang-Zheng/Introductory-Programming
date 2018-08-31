#include <stdio.h> 

unsigned long long int fibonacci(unsigned int n);

int main(void)
{
	unsigned int number;
	printf("%s", "enter an integer:");
    scanf_s("%d", &number, 1);
	unsigned long long int result = fibonacci(number);
	printf("Fibonacci(%u)=%11u\n", number, result);
	getchar();
	getchar();
}

unsigned long long fibonacci(unsigned int n)
{
	if (0 == n || 1 == n) {
		return n;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}