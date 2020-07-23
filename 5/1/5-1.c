#include <stdio.h>
#include <ctype.h>
#define SIZE 10

int getint(int *output);
int getch();
void ungetch(int ch);

static int ch;
static int ch_set = 0;

int main()
{
	int n, o, array[SIZE];
	for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	
	for(o = 0; o < n; o++)
		printf("%d\n", array[o]);	
}

int getint(int *output)
{
	int c, sign;
	
	while(isspace(c = getch()))
		;
		
	if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return EOF;
	}
	
	sign = (c == '-') ? -1 : 1;
	
	if(c == '+' || c == '-') {
		c = getch();
		if(!isdigit(c) && c != EOF) {
			ungetch(c);
			return EOF;
		}
	}
	
	for(*output = 0; isdigit(c); c = getch())
		*output = 10 * *output + (c - '0');
	
	*output *= sign;
	
	if(c != EOF)
		ungetch(c);
		
	return c;
}

void ungetch(int c)
{
	if(c == EOF)
		return;
		
	ch_set = 1;
	ch = c;
}

int getch()
{
	if(ch_set == 1) {
		ch_set = 0;
		return ch;
	}
	
	return getchar();
}
