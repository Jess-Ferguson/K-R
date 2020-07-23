#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

int main()
{
	
	return 0;
}

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("Ungetch: too many chars\n");
	else
		buf[bufp++] = c;
}

void ungets(char s[])
{
	int i;
	
	for(i = strlen(s); bufp < BUFSIZE && i >= 0; i--)
		ungetch(s[i]);
}
