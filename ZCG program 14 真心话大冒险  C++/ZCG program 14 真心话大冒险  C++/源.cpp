
#include <stdio.h>
#include <time.h>
#include<iostream>


int main()
{
	int x, y, z, h;
	enum status {a,b,c,d,e,f};
	srand(time(0));
	int i = 1 + rand() % 10;
	printf("%d\n", i);
	switch (i) 
	{
	case 1:
		puts("lucky,just drink a cup of cola.");
		break;
	case 2:
		printf("hug sb.");
		break;
	case 3:
		printf("good,you can ask sb to do sth for you.");
		break;
	case 4:
		printf("every one near you can ask you sth to do.");
		break;
	
	    default:
		     printf("you need to answer the question or you need do what i ask you to do.\n");
		     printf("the question is: James Chadwick find the neutron and the question is when he died?\nhe pass away in:");
		     scanf_s("%d %d %d %d", &x,&y,&z,&h);
		     if ((x==1)&&(y==9)&&(z==7)&&(h==4)) {
			     printf("\ngood luck,your answer is right!");
		      }
		     else {
			     printf("\nsorry you lose , tell sb 'I love you' >>>>");
				 getchar();
				 getchar();
				 getchar();
				 getchar();
		      }
	   break;
	}
	getchar();
	getchar();
}