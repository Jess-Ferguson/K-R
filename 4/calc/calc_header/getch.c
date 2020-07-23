#include <stdio.h>
#define BUFSIZE 128

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(c == EOF)
		return;
		
	if(bufp >= BUFSIZE)
		printf("Ungetch: too many chars\n");
	else
		buf[bufp++] = c;
}

