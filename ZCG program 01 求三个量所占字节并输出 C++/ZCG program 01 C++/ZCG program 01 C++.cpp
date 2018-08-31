#include <stdio.h> 
#include "stdafx.h"
int main() {
	int integer_size;
	int character_size;
	int float_size;

	integer_size = sizeof(int);
	character_size = sizeof(char);
	float_size = sizeof(float);

	printf("int,char,float,double use %d and %d and %d and %d bytes\n",
		integer_size, character_size, float_size, sizeof(double));
	getchar();
	return 0;
}