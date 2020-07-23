// 1-19.c - Program that reverses it's input and prints it
#include <stdio.h>
#define MAXLEN 1024

int get_line(char s[], int lim);
void reverse(char s[]);

int main()
{
	int len, max;
	char line[MAXLEN], longest[MAXLEN];
	
	max = 0;
	
	while((len = get_line(line, MAXLEN)) > 0) {
		reverse(line);
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

void reverse(char s[])
{
	int i, j, k, newl;
	
	i = 0;
	while(s[i] != '\0')
		i++;
	
	i--;
	
	if(s[i] == '\n') {
		i--;
		newl = 1;
	} else {
		newl = 0;
	}
	
	for(j = 0; j <= i/2; j++) {
		k = s[j];
		s[j] = s[i - j];
		s[i - j] = k;
	}
	
	if(newl)
		s[++i] = '\n';
}
