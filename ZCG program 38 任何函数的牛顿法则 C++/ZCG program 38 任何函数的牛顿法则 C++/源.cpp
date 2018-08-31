#include <stdio.h>
#include <math.h>
float ff(float coeff[10],int roots[10],float root,int needc,int needr) {
	float answer=0; 
	for (int x = 0; x < needr; x++) {
		float answer = roots[x] * pow(root, coeff[x])+roots[x+1];
	}
	return answer;
}
float FF(float coeff[10], int roots[10], float root, int needc, int needr) {
	float answer=0;
	for (int x = 0; x < needr; x++) {
		answer = roots[x] * coeff[x] * pow(root, (coeff[x] - 1));
	}
	return answer;
}
int main() {
	float coeff[10];
	int roots[10];
	float discrim, denom, root_1, root_2;
	float yroot, answer[100], k, root;
	int n, needc,needr, h;
	printf("please input the number of coefficient:");
	scanf_s("%d", &needc);
	printf("\nplease input the number of root:");
	scanf_s("%f", &needr);
	
	for(h=0;h<=needc-1;h++){
		n = h + 1;
	printf("\nplease input your %dth coefficient:",n); 
	scanf_s("%f", &coeff[0]); 
	}
	for (h = 0; h <= needr-1; h++) {
		int b = h + 1;
		printf("please input your %dth root:",b);  //promt
		scanf_s("%f", &roots[0]); //read and store
	}
	for (n = 0; n <= 99; n++) {
		answer[n] = 0;
	}
	for (n = 0; n <= 9; n++) {
		roots[n] = 0;
	}
	for (n = 0; n <= 9; n++) {
		coeff[n] = 0;
	}
	printf("\nguess the root:");
	scanf_s("%f", &root);
	printf("\n");
	for (n = 0; n <=100; n++) {
		float f=ff(coeff,  roots, root, needc,  needr);
		float F = FF(coeff, roots,  root,  needc,  needr);
		root = root - f / F;
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