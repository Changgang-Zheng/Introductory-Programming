#include <stdio.h>
int main() {
	int hight;
	int weight;
	int old;
	char name[100];

    puts("look at me and gess my weight is_1_and weight is_2_and how old is me_3_and my english name is_4_");

	printf("answer 1 is:\n");
	scanf_s("%d", &hight,1);

	printf("answer 2 is:\n");
	scanf_s("%d",&weight,1);

	printf("answer 3 is:\n");
	scanf_s("%d",&old,1);

	printf("answer 4 is:\n");
	scanf_s("%100s", &name[0], 100);

	printf("my hight is %d and my weight is %d and i am %d years old and my english name is %s",hight, weight, old, name);
	getchar();
	getchar();
	return 0 ;
 }