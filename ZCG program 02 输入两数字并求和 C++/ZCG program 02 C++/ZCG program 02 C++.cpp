// ZCG program 02 C++.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	int operand1, operand2, sum;
	
	printf("enter first operand\n");
	scanf_s("%d", &operand1,1);//read an integer ������Ϣ

	printf("enter second operand\n");
	scanf_s("%d", &operand2,1);//read an integer ������Ϣ

	sum = operand1 + operand2;
	printf("the result is %d\n", sum);//give out the answer ������
	getchar();
	return 0;

}

