#include <stdio.h>

int main() {
	int x;
	x = 161;
	char name[100] = "C.G.musk";
	printf("Hi there!  %s is my english name!", name);

	float y = 61;
	printf("y is currently my beight %f.\n", y);
	printf("Make that shorter: %.2f.\n", y);
	printf("Make that longer: %.8f.\n\n", y);

	int z;
	z = y /x;
	z = z / y + 2;
	printf("Why does z,it is weight/height = %i\n\n", z);

	printf("We can print all of the number ");
	printf("it is: %i %f %i\n\n", x, y, z);

	char a = 71;
	printf("Which is transform into a character and you can find 72 can be transformed into h: %c\n", a);

	// wait for a keypress
	getchar();
}

