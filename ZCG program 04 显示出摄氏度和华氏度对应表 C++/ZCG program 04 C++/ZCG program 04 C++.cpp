// ZCG program 04 C++.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"

#include <stdio.h>
 int main(){
	 float celsius, fahr;
	 float lower, upper, step;
	 
	 lower = 0;
	 upper = 100;
	 step = 1;

	 fahr = lower;
	 while (fahr <= upper) {
		 celsius = (0.5 / 0.9)*(fahr - 32.0);
		 printf("teprature of cahr is %f and  celsius is %f \n", fahr, celsius);//the word and rhe date which you can see on the answer board
		 fahr = fahr + step;
	 }
	 getchar();//make the answer board do not open
	 return 0;
}

