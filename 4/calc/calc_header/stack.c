#include "calc.h"
#define MAXVAL 128
extern int sp;
extern double val[];

double pop(void)
{
	if(sp > 0)
		return val[--sp];
	
	printf("Error: bottom of stack reached\n");
	return 0.0;
}

void push(double n)
{
	if(sp < MAXVAL)
		val[sp++] = n;
	else
		printf("Error: Stack full\n");
}
