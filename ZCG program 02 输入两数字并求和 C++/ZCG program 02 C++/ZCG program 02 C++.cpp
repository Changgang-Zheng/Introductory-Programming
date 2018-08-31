// ZCG program 02 C++.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int operand1, operand2, sum;
	
	printf("enter first operand\n");
	scanf_s("%d", &operand1,1);//read an integer 输入信息

	printf("enter second operand\n");
	scanf_s("%d", &operand2,1);//read an integer 输入信息

	sum = operand1 + operand2;
	printf("the result is %d\n", sum);//give out the answer 输出结果
	getchar();
	return 0;

}

