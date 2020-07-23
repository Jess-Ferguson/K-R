#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define SIZE 512

int getdouble(double *output);
int getch();
void ungetch(int ch);

static int ch;
static int ch_set = 0;

int main()
{
	int n, o;
	double array[SIZE];
	for(n = 0; n < SIZE && getdouble(&array[n]) != EOF; n++)
		;
	
	for(o = 0; o < n; o++)
		printf("%10.8f\n", array[o]);
	
	return 0;
}

int getdouble(double *output)
{
	int c, sign, dec = 0;
	
	while(isspace(c = getch()))
		;
		
	if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return EOF;
	}
	
	sign = (c == '-') ? -1 : 1;
	
	if(c == '+' || c == '-' || (c == '.' && (dec = 1))) {
		c = getch();
		if(!isdigit(c) && c != EOF) {
			ungetch(c);
			return EOF;
		}
	}
	
	for(*output = 0; isdigit(c) || (c == '.' && dec == 0); c = getch()) {
		if(dec == 0) {
			if(c == '.') {
				dec++;
				continue;
			}
			*output = 10 * *output + (c - '0');
		} else {
			*output += (c - '0') / pow(10, dec++);
		}
	}
	
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
