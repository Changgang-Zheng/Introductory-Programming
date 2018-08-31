#include <stdio.h>
int catYears(int human_years) {
	float y = human_years / 7.0;
	// this would be a good place for a comment
	// why did I write the next line?
	int rounded = y + 0.5;
	return rounded;
}
float sumOfSquares(float a, float b) {
	return a*a + b*b;
}
void p(int years, float c, char animal[100]) {
	printf("If I were a %s, I'd be ", animal);
	printf("%i years old.\n\n", years);
	printf("The sum of squares ");
	printf("was %f units.\n", c);
}
int main() {
	int my_age = 18;
	float x = 3.3;
	char animal[100] = "cat";
	float years_a = catYears(my_age);
	float sum = sumOfSquares(x, 7.4);
	p(years_a, sum, animal);
	// wait for a keypress
	getchar();
}