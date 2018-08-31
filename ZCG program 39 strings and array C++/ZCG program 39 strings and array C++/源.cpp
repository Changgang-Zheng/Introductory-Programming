#include <stdio.h>
#include <string.h>
void CLI(int characterword, int sentence, int word) {
	float cli;
	cli = 5.89*characterword / word - 29.5*sentence / word - 15.8;
	printf("the real score is %.1f\n", cli);
	if (cli < 1) {
		printf("the final score is 1");
	}
	else {
		printf("the final score is %.1f", cli);
	}
}

void calculateandprint(char text[500]) {
	int characters = strlen(text), sentences, o, characterword, comma=0;
	int words = 0;
	printf("there are totally %d charaters\n", characters);
	sentences = 0;

	for (o = 0; o < characters; o++) {
		if (text[o] == '.') {
			sentences++;
		}
		if (text[o] == ',') {
			comma++;
		}
		if (text[o] == ' ') {
			words++;
		}
		printf("%c", text[o]);
	}
	
	characterword = characters - comma - sentences-words;
	printf("\nthere are %d charaterword", characterword);
	printf("\nthere are %d sentance\n", sentences);
	words = words + 1;
	printf("there are %d words\n", words);
	CLI(characterword, sentences, words);
	getchar();
}

int main() {
	char text2[1000] = "Existing computer programs that measure readability are based largely upon subroutines which estimate number of syllables, usually by counting vowels. The shortcoming in estimating syllables is that it necessitates keypunching the prose into the computer. There is no need to estimate syllables since word length in letters is a better predictor of readability than word length in syllables. Therefore, a new readability formula was computed that has for its predictors letters per hundred words and sentences per hundred words. Both predictors can be counted by an optical scanning device, and thus the formula makes it economically feasible for an organization such as the US Office of Education to calibrate the readability of all textbooks for the public school system.";
	
	char text1[100] = "I like cats. Cats like me. Miao miao miao. Dogs are bad. Bad dogs bad.";

	calculateandprint(text1);
	calculateandprint(text2);
	getchar();
}
