#include <stdio.h>
int main(){
	int c, d, i, p, nwite, nother;
	int ndigit[10];
	nwite = nother = 0;
	p = 0;
	for (i = 0 ; i < 10 ; i = i + 1) 
		ndigit[i] = 0;
	while ((c = getchar()) !='e') {
		if (c >= '0'&&c <= '9') {
			ndigit[c - '0'] = ndigit[c - '0'] + 1;

		}
		else if (c == ' ' || c == '\n' || c == '\t') {
			nwite = nwite + 1;
		}
		else {
			nother = nother + 1;
		}
	}
	for (c = 0; c < 10; c++) {
		printf("number %d appears in %d time\n", c, ndigit[c]);	
	}
	    printf("white number is %d\n", nwite);
	    printf("nother number is %d\n", nother);
	getchar();
	getchar();
	return(0);
}
