#include <stdio.h>
#include <math.h>
int main() {
	float a, b, c, o, p;
	float discrim, denom, root_1, root_2;

	printf("\n a=");  //promt
	scanf_s("%f", &a,1); //read and store
	printf("\n b=");
	scanf_s("%f", &b,1);
	printf("\n c=");
	scanf_s("%f", &c,1);
	getchar();
    discrim = pow(b, 2) - 4 * a*c; //判定
	denom = 2 * a; //分母项
	root_1 = (-b + sqrt(discrim)) / denom; //根1
	root_2 = (-b - sqrt(discrim)) / denom; //根2
	//以上为二元一次方程求根过程
	printf(" roots 1 is \n X1=");
    scanf_s("f%", &o,1 );
    printf(" roots 2 is \n X2=");
	scanf_s("f%", &p ,1);
	getchar();//input our own answer
		if (o == root_1) {
		    printf("\n the answer X1 is right");
			o = root_1 + 1;
			}
		if (p == root_2) {
				printf("\n the answer X2 is right");
				p = root_2 + 1;
			}
	printf("\n cogratulations! your answer is right!!");
	getchar();
	getchar();
	return 0;
}

 