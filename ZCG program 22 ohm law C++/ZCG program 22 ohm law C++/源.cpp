#include <stdio.h>

float ohmlaw(float u, float r) {
	float i;
	i = u / r;
	printf("the detour I is %f", i);
	return i;
}
float paralleling2(float rp1, float rp2) {
	float rp;
	rp = rp1*rp2 / (rp1 + rp2);

	return rp;
}
float series2 (float rs1, float rs2) {
	float rs;
	rs = rs1 + rs2;
	return rs;
}
float paralleling3(float r31, float r32,float r33) {
	float r3;
	r3 = (r31* r32 *r33 /( r31*r32 + r31*r33 + r32*r33));
	return r3;
}
float trasform(float Ir){
	float IR;
	IR = Ir * 1000;
	return IR;
}
int main(void) {
	float R[7];
	int U;
	int n;
	float R1, R2, R3, R4, R0, Ir, IR;
	
	printf("input U please\n");
	scanf_s("%d",&U);
	for (n = 0; n <= 6; n++) {
		int m = n + 1;
		printf("\n input Resistor%d \n", m);
		scanf_s("%f", &R[n], 1);
	}
	
	R1 = series2(R[0], R[1]);
	R2 = paralleling2(R[2], R[3]);
	R3 = paralleling2(R[5], R[6]);
	R4 = series2(R[4], R3);
	R0 = paralleling3(R1, R2, R4);
	Ir = ohmlaw(U, R0);
	IR = trasform(Ir);
	printf("\nbut %.1f mA is the real answer~~~~",IR);
	getchar();
	getchar();
}