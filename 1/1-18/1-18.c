// 1-18.c - Program to strip lines of any trailing whitespace characters and delete completely blank lines
#include <stdio.h>
#define MAXLEN 1024

int get_line(char s[], int lim);
int rem_blanks(char s[], int len);

int main()
{
	int len;
	char line[MAXLEN];
	
	while((len = get_line(line, MAXLEN)) > 0) {
		if(rem_blanks(line, len) > 0)
			printf("%s", line);
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

int rem_blanks(char s[], int len)
{
	int i, newl;
	newl = (s[len - 1] == '\n');
	
	for(i = len - 1; i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'); --i)
		s[i] = '\0';	
	
	if(newl)
		s[++i] = '\n';
	
	return i;
}
