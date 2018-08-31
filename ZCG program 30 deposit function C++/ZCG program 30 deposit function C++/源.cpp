#include <stdio.h>
#include <stdlib.h>  // extra includes!
#include <time.h>
#include <math.h>

float getRand() {
	return rand() / (RAND_MAX + 1.0);
}

int compare(int p, int q) {
	if (p < q) {
		printf("your answer is too high\n");
	}
	else {
		printf("your answer is too low\n");
	}
	return 0;
}

int comparefloat(float p, float q) {
	if (p < q) {
		printf("your answer is too high\n");
	}
	else {
		printf("your answer is too low\n");
	}
	return 1;
}


int number(int x) {
	float sizeFP;
	int size;
	sizeFP = getRand() * x + 1;
	size = floor(sizeFP);
	return size;
}

float numberfloat(int y) {
	float sizeFP;
	sizeFP = getRand() * y;
	return sizeFP;
}

int correct_answer(int n, int value) {
	int g;
	printf("guess it(your %dth choice)\n", n);
	scanf_s("%d", &g);
	if (g != value) {
		compare(value, g);
		return 0;
	}
	else {
		printf("\nthe right answer is %d\n", value);
		printf("you win after your %dth try\n", n);
		return 1;
	}
}

int correct_answerfloat(int n, float valuefloat) {
	float g;
	printf("guess it(your %dth choice)\n", n);
	scanf_s("%f", &g);
	if ((-0.1 > g - valuefloat) || (g - valuefloat >0.1)) {
		comparefloat(valuefloat, g);
		return 0;
	}
	else {
		printf("\nthe right answer is %.1f\n", valuefloat);
		printf("you win after your %dth try\n", n);
		return 1;
	}
}


int main() {
	int value;
	int n, m, all, rep;
	int min_number;
	float valuefloat;
	min_number = 100;
	srand(time(NULL)); // init random
	getRand(); // kick-start the random numbers
	do {
		printf("game 1 guess an int number between 1 to 32\n");
		n = 1;
		value = number(32);
		while (correct_answer(n, value) == 0) {
			n = n + 1;
		}
		if (n<min_number)
			min_number = n;
		// guess float number 
		printf("\n\ngame 2 guess a float number between 0 to 32 (point 1)\n");
		m = 1;
		valuefloat = numberfloat(32);
		while (correct_answerfloat(m, valuefloat) == 0) {
			m = m + 1;
		}
		if (m<min_number)
			min_number = m;
		if (n>5 || m>5) {
			printf("your try number is too high，you must run again\n");
			rep = 1;
		}
		else
			rep = 0;
	} while (rep);
	printf("\nyou win! The min try number is %d ", min_number);
	getchar();
	getchar();
}