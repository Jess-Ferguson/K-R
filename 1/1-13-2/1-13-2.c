#include <stdio.h>
#define MAXLEN 256

int main()
{
	int c, word_len[MAXLEN], longest = 0;
	int len = 0;
	
	for(int i = 0; i < MAXLEN; i++)
		word_len[i] = 0;
	
	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\n' || c == '\t') {
			if(len > 256)
				len = 256;
			
			word_len[len]++;
			
			if(word_len[len] > longest)
				longest = word_len[len];
			
			len = 0;
		} else {
			len++;
		}
	}
	
	for(int i = 1; i < MAXLEN; i++) 
		if(word_len[i] > 0)
			printf("%d\t", i);
	
	putchar('\n');
	
	for(int i = 0; i < longest; i++) {
		for(int j = 1; j < MAXLEN; j++) {
			if(word_len[j] > i)
				printf("#\t");
			else if(word_len[j] > 0)
				putchar('\t');
		}
		putchar('\n');
	}
	
	return 0;
}
