#include <stdio.h>
#include <stdlib.h>  // extra includes!
#include <time.h>
/* Get a random number from 0 to 0.9999999
(you don't need to understand this function)
***** DON'T MODIFY THIS FUNCTION *****
*/
float getRand() {
	return rand() / (RAND_MAX + 1.0);
}
int main() {
	srand(time(NULL)); // init random
	getRand(); // kick-start the random numbers
	float number = getRand();
	printf("Random number: %f\n", number);
	getchar();
}
