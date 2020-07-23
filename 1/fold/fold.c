/* fold.c - Folds long lines into two or more shorter ones after last non blank character, If no non blanks are found, fold at BLOCK_SIZE regardless and process next line */

#include <stdio.h>
#define BLOCK_SIZE 10
#define MAX_LEN 1024

int get_line(char s[], int lim);

int main()
{
	int len, i, j, k, l;
	char line[MAX_LEN];
	
	while((len = get_line(line, MAX_LEN)) > 0) {
		for(i = 1 + (len / BLOCK_SIZE), k = 0; i >= 0; i--) { // While there is a block > 10 chars
			for(j = BLOCK_SIZE; j > 0; j--) // Traverse the block backwards
				if(line[k + j] == ' ' || line[k + j] == '\t') {
					l = k + j; // Position of newline
					break;
				}
			
			if(!j) // If no blanks are found
				l = k + BLOCK_SIZE;
			
			while(k < l && line[k] != '\0')
				putchar(line[k++]);
			
			putchar('\n');
		}
		
		while(line[k] != '\0')
			putchar(line[k++]);
	}
}

int get_line(char s[], int lim)
{
	int c, i;
	
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if(i < lim - 1)
			s[i] = c;
	
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
	
	return i;
}
