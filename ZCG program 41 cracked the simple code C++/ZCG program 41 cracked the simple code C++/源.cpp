#include <stdio.h>
#include<math.h>

struct tempgroups {
	int x = 0;
	int y = 0;
};

struct tempgroups crackfrommask(int mask) {
	struct tempgroups first;
	int tempmask;
	int binary[100];
	tempmask = mask ^ 31337;
	int i;
	for (i = 0; i <= 14; i++) {
		binary[i] = tempmask % 2;
		tempmask = tempmask / 2;
	}
	int s;
	for (i = 8; i <= 14; i++) {
		s = 0;
		s = pow(2, i - 8)*binary[i];
		first.x = first.x + s;
	}
	for (i = 0; i < 7; i++) {
		s = 0;
		s = pow(2, i)*binary[i];
		first.y = first.y + s;
	}
	return first;
}

void answer(struct tempgroups third) {
	char x = third.x;
	char y = third.y;
	if ((x >= 32) && (x <= 122)) {
		printf("%c", x);
	}
	else {
		printf("_");
	}
	if ((y >= 32) && (y <= 122)) {
		printf("%c", y);
	}
	else {
		printf("_");
	}
}

int main() {
	struct tempgroups second_group;
	int mask;
	mask = 15643;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 6913;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 6916;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 23040;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 2377;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 6985;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 6408;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 3657;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 5638;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 3084;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 2119;
	second_group = crackfrommask(mask);
	answer(second_group);

	printf("\n");

	mask = 15910;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 23079;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 13629;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 23101;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 10300;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 10557;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 23073;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 13092;
	second_group = crackfrommask(mask);
	answer(second_group);
	mask = 23369;
	second_group = crackfrommask(mask);
	answer(second_group);

	getchar();
	getchar();
	return 0;
}