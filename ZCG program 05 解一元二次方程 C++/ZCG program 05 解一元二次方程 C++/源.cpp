#include <stdio.h>
#include <math.h>
int main() {
	float coeff_1, coeff_2, coeff_3;
	float discrim, denom, root_1, root_2;

	printf("\nfirst coefficient");  //promt
	scanf_s("%f", &coeff_1); //read and store
	printf("\n2nd coefficent");
	scanf_s("%f", &coeff_2);
	printf("\n3rd coefficient");
	scanf_s("%f", &coeff_3);

	discrim = pow(coeff_2, 2) - 4 * coeff_1*coeff_3; //判定
	denom = 2 * coeff_1; //分母项
	root_1 = (-coeff_2 + sqrt(discrim)) / denom; //根1
	root_2 = (-coeff_2 - sqrt(discrim)) / denom; //根2
	printf("roots are %f %f\n", root_1, root_2);
	getchar();
	return 0;
}