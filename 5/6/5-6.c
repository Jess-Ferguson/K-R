#include <stdio.h>
#define MAXLINE 1024

int getlinep(char *s, int lim);
int strindexp(char *s, char *t);

int main()
{
	char s[MAXLINE];
	char *match = "test";
	int pos;
	int chars;
	
	while((chars = getlinep(s, MAXLINE)) > 0) {
		if((pos = strindexp(s, match)) >= 0)
			printf("Found \"%s\" in \"%s\" at position %d (read %d characters)\n", match, s, pos, chars);
		else
			printf("No match! (read %d characters)\n", chars);
	}
	
	return 0;
}

int getlinep(char *s, int lim)
{
	int i;
	
	for(i = 0; i < lim - 1 && (*s = getchar()) != EOF && *s != '\n'; i++, s++)
		;
	
	/*if(*s == '\n') {
		i++;
		s++;
	}*/
	
	*s = '\0';
	
	return i;
}

int strindexp(char *s, char *t)
{
	char *u, *v, *w;
	
	for(v = s; *s; s++) {
		for(u = s, w = t; *u == *w; u++, w++)
			;
		if(!*w)
			return s - v;
	}
	
	return -1;
}
