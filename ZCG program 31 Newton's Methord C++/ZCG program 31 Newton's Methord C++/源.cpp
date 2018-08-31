#include <stdio.h>
#include <math.h>
float tangent(float Guessroot,float Yroot, float K) {
	float rootagain;
	rootagain = Guessroot - Yroot/ K;
	return rootagain;
}
float xy(float guessrooT, float coefF_1, float coefF_2, float coefF_3) {
	float  yrooT;
	yrooT = guessrooT*guessrooT*coefF_1 + coefF_2*guessrooT + coefF_3;
	return yrooT;
}
float K(float guessroOT,float coeFF_1,float  coeFF_2,float coeFF_3) {
	float k;
	k = 2 * coeFF_1*guessroOT + coeFF_2;
	return k;
}
int main() {
	float coeff_1, coeff_2, coeff_3;
	float discrim, denom, root_1, root_2;
	float yroot, answer[100], k, root;
	int n;

	printf("please input your 1st coefficient:");  //promt
	scanf_s("%f", &coeff_1); //read and store
	printf("please input your 2nd coefficent:");
	scanf_s("%f", &coeff_2);
	printf("please input your 3rd coefficient:");
	scanf_s("%f", &coeff_3);

	discrim = pow(coeff_2, 2) - 4 * coeff_1*coeff_3; //判定
	denom = 2 * coeff_1; //分母项
	root_1 = (-coeff_2 + sqrt(discrim)) / denom; //根1
	root_2 = (-coeff_2 - sqrt(discrim)) / denom; //根2
	printf("\nroots are X1=%f X2=%f\n", root_1, root_2);
	for (n = 0; n <= 99; n++) {
		answer[n] = 0;
	}
	printf("\nguess the root:");
	scanf_s("%f", &root);
	printf("\n");
	for (n = 0; n <= 99; n++) {
		yroot = xy(root, coeff_1, coeff_2, coeff_3);
		k = K(root, coeff_1, coeff_2, coeff_3);
		root = tangent(root, yroot, k);
		answer[n] = root;
	}
	for (n = 0; n <= 99; n++) {
		int b = n + 1;
		printf("the root%d is %.9f\n", b, answer[n]);
	}
    getchar();
	getchar();
	return 0;
}