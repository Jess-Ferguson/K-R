#include <stdio.h>
#define MAXLEN 256

int main()
{
	int c, word_len[MAXLEN];
	int len = 0;
	
	for(int i = 0; i < MAXLEN; i++)
		word_len[i] = 0;
	
	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\n' || c == '\t') {
			if(len > 256)
				len = 256;
			word_len[len]++;
			len = 0;
		} else {
			len++;
		}
	}
	
	for(int i = 1; i < MAXLEN; i++) {
		if(word_len[i] > 0) {
			printf("%d: ", i);
			for(int j = 0; j < word_len[i]; j++) {
				putchar('#');
			}
			putchar('\n');
		}
	}
	
	return 0;
}
