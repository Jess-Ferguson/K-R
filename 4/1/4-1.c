#include <stdio.h>
#define MAXLINE 1024

int get_line(char s[], int lim);
int strrindex(char s[], char t[]);

int main()
{
	char pattern[] = "ould";
	char line[MAXLINE];
	int found = 0;
	int pos;
		
	while(get_line(line, MAXLINE) > 0)
		if((pos = strrindex(line, pattern)) >= 0) {
			printf("%sRightmost occurence at %d\n", line, pos);
			found++;
		}
		
	return found;
}

int get_line(char s[], int lim)
{
	int c, i;
	
	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strrindex(char s[], char t[])
{
	int i, j, k, l;
	
	l = -1;
	
	for(i = 0; s[i] != '\0'; i++) {
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0')
			l = j - k;
	}
	return l;
}
