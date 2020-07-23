// detab.c - Program that replaces tabs with the correct number of spaces to bring it to the next tab stop
#include <stdio.h>
#define MAXLEN 1024
#define TAB_WIDTH 8

int get_line(char s[], int lim);

int main()
{
	int len, i, j, k;
	char line[MAXLEN];
	
	while((len = get_line(line, MAXLEN)) > 0)
		for(i = 0, k = 1; line[i] != '\0'; i++, k++) {
			if(line[i] == '\t')
				for(j = TAB_WIDTH - (k % TAB_WIDTH), k += j; j >= 0; j--)
					putchar(' ');
			else
				putchar(line[i]);
		}
	
	return 0;
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

