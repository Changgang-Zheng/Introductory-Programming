#include <stdio.h>
int main(void)
{
	int n[6] = { 32,27,64,18,95,112 };
	printf("%5s%20s\n", "elemant", "value");
	for (size_t i = 0; i < 6; ++i)
	{
		printf("%7u%20d\n", i, n[i]);
		getchar();
	}
}