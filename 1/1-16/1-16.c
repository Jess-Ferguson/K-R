#include <stdio.h>
#define MAXLEN 32

int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
	int len, max;
	char line[MAXLEN], longest[MAXLEN];
	
	max = 0;
	
	while((len = get_line(line, MAXLEN)) > 0)
		if(len > max) {
			max = len;
			copy(longest, line);
		}
	
	if(max > 0)
		printf("%s\n%d\n", longest, max);
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

void copy(char to[], char from[])
{
	int i = 0;
	
	while((to[i] = from[i]) != '\0')
		i++;
}
