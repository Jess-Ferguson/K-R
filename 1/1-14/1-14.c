#include <stdio.h>
#define CHAR_NO 12


int main()
{
	int c, char_count[CHAR_NO];
	int len = 0;
	
	for(int i = 0; i < CHAR_NO; i++)
		char_count[i] = 0;
	
	while((c = getchar()) != EOF) {
		if(c - '0' >= 0 && c - '0' <= 9) {
			char_count[c - '0']++;
		} else if(c == '\n' || c == ' ' || c == '\t') {
			char_count[11]++;
		} else {
			char_count[12]++;
		}
	}
	
	for(int i = 0; i < CHAR_NO; i++) {
		if(char_count[i] > 0) {
			if(i < 10)
				printf("%d: ", i);
			else if(i == 10)
				printf("Whitespace: ");
			else if(i == 11)
				printf("Other: ");
			
			for(int j = 0; j < char_count[i]; j++) {
				putchar('#');
			}
			
			putchar('\n');
		}
	}
	
	return 0;
}
