#include <stdio.h>
#include <stdlib.h>  // extra includes!
#include <time.h>
#include <math.h>

float getRand1() {
	return  rand() / (RAND_MAX + 1.0);
}

float getRand2() {
	return 1/(rand() / (RAND_MAX + 1.0));
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

float comparefloat (float p, float q) {
	if (p < q) {
		printf("your answer is too high\n");
	}
	else {
		printf("your answer is too low\n");
	}
	return 0;
}

int numberwrong(int a) {
	int i = 0;
	int ran = getRand1();
	while (ran < (float)i / a) {
		i = i + 1;
	}
	return i;
}

int number(int x) {
	float sizeF, sizeFP;
	int size;
	sizeFP = getRand1() * 32 + 1;
	sizeF = floor(sizeFP);
	return sizeF;
}

float numberfloat(int y) {
	float sizeF, sizeFP;
	float sizefloat;
	sizeFP = getRand1() * y ;
	return sizeFP;
}

int comparescorefunction(int times,int comparescore[50]) {
	int scanfinput;
	int measure, realmeasure;
	float board;
	int pointer1 = 0;
	int pointer2 = 1;
	int m, n;

	measure = times;
	
	realmeasure = measure - 1;
	for (pointer1 = 0; pointer1 >= realmeasure; pointer1++) {
		for (pointer2 = pointer1 + 1; pointer2 >= realmeasure; pointer2++) {
			if (comparescore[pointer1] < comparescore[pointer2]) {
				board = comparescore[pointer1];
				comparescore[pointer1] = comparescore[pointer2];
				comparescore[pointer2] = board;
			}
		}
	}
	getchar();
	getchar();
	m = 0;
	for (n = 0; n < 50; n++) {
		m = n + 1;
		printf("the %dth score is %d", m, comparescore[n]);
	}
	return 0;
}

int numberhighest(int high) {
	float sizeF, sizeFP;
	int size;
	sizeFP = getRand2();
	printf("value=%f", sizeFP);
	sizeF = floor(sizeFP);
	return sizeF;
}

int main() {
	int value = 0;
	int choose, r, s, t, o, x, b, y, all, highest, comparescore[50], times, ni;
	float valuefloat, h;
	for (ni = 0; ni < 50; ni++) {
		comparescore[ni] = 100000;
	}
	srand(time(NULL)); // init random
	getRand1(); // kick-start the random numbers
	getRand2();
	do {
		times = 0;
		printf("game 1 guess an int number between 1 to 32\n");
		r = 0;
		s = 5;
		t = r + 1;
		choose = 0;
		value = number(32);
		printf("right answer is %d\n", value);
		int g[32];
		printf("gess it(your %dth choice)", t);
		scanf_s("%d", &g[r]);
		while (g[r] != value) {
			compare(value, g[r]);
			r = r + 1;
			t = r + 1;
			printf("your answer is wrong and guess again\n");
			printf("\ngess it(your %dth choice)", t);
			scanf_s("%d", &g[r]);
		}
		printf("\nthe right answer is %d\n", value);
		printf("you win after your %dth try which is your score\n", t);
		comparescore[times] = t;
		// change change change change change change change 
		printf("\n\ngame 2 guess a float number between 0 to 32 (point 1)\n");
		o = 0;
		s = 5;
		x = 0;
		b = o + 1;
		choose = 0;
		valuefloat = numberfloat(32);
		printf("right answer is %.1f\n", valuefloat);
		printf("gess it(your %dth choice)", b);
		scanf_s("%f", &h);
		while (-0.1 > h - valuefloat || h - valuefloat > 0.1) {
			comparefloat(valuefloat, h);
			b = b + 1;
			printf("your answer is wrong and guess again\n");
			printf("\ngess it(your %dth choice)", b);
			scanf_s("%f", &h);
		}
		printf("\nthe right answer is %.1f\n", valuefloat);
		printf("you win after your %dth try which is your score\n", b);
		all = b + t;
		times = times + 1;
		comparescore[times] = b;
		printf("\nyou try in %d times\n", all);
		if (b < t) {
			printf("your best score is %d\n", b);
		}
		else {
			printf("your best score is %d\n", t);
		}
	} while(all>8&&b>1&&t>1);
	//............compare.........
	int scanfinput;
	int measure, realmeasure;
	float board;
	int pointer1 = 0;
	int pointer2 = 1;
	int m, n;
	measure = 50;
    realmeasure = measure - 1;
	for (pointer1 = 0; pointer1 <= realmeasure; pointer1++) {
		for (pointer2 = pointer1 + 1; pointer2 <= realmeasure; pointer2++) {
			if (comparescore[pointer1] > comparescore[pointer2]) {
				board = comparescore[pointer1];
				comparescore[pointer1] = comparescore[pointer2];
				comparescore[pointer2] = board;
			}
		}
	}
	m = 0;
	for (n = 0; n < times; n++) {
		m = n + 1;
		printf("%d %d", m, comparescore[n]);
		
	}//compare compare..........................


	printf("\nyou win~~~~when you win, you try in %d times",all);
	//extra extra extra extra
	printf("\n\nextra game 1, guess an int number between 1 to ???\n");
	r = 0;
	s = 5;
	t = r + 1;
	choose = 0;
	value = numberhighest(0);
	printf("right answer is %d\n", value);
	printf("gess it(your %dth choice)", t);
	int k;
	scanf_s("%d", &k);
	while (k != value) {
		compare(value, k);
		r = r + 1;
		t = r + 1;
		printf("your answer is wrong and guess again\n");
		printf("\ngess it(your %dth choice)", t);
		scanf_s("%d", &k);
	}
	printf("\nthe right answer is %d\n", value);
	printf("you win extra game 1 after your %dth try\n", t);
	//extra 2 extra 2
	printf("\nextra game 2, guess an int number between 101 to 132\n");
	o = 0;
	s = 5;
	t = o + 1;
	choose = 0;
	value= 100+number(32);
	printf("right answer is %d\n", value);
	printf("gess it(your %dth choice)", t);
	scanf_s("%d", &k);
	while (k!=value) {
		compare(value, k);
		t = t + 1;
		printf("your answer is wrong and guess again\n");
		printf("\ngess it(your %dth choice)", t);
		scanf_s("%f", &k);
	}
	printf("\nthe right answer is %d\n", value);
	printf("you win extra game 2 after your %dth try\n", t);
	getchar();
	getchar();
}