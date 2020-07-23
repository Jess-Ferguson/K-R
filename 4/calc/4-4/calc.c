#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define COMMAND '1'
#define SPEC_OP '2'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char s[]);
int getcha();
void push(double n);
void ungetcha(int c);
double pop();
void clear();

int sp = 0;
int bufp = 0;
double val[MAXVAL];
char buf[BUFSIZE];

int main()
{
	int type;
	double t1, t2;
	char s[MAXOP];
	
	while((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case 'c':
				clear();
				break;
			case 'p':
				if(sp > 0)
					printf("%.8g\n", val[sp - 1]);
				else
					printf("Error: bottom of stack reached\n");
				break;
			case 'd':
				t1 = pop();
				push(t1);
				push(t1);
				break;
			case 's':
				t1 = pop();
				t2 = pop();
				push(t1);
				push(t2);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				t1 = pop();
				push(pop() - t1);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				t1 = pop();
				if(t1 != 0.0)
					push(pop() / t1);
				else
					printf("Error: division by zero\n");
				break;
			case '%':
				t1 = pop();
				if(t1 != 0.0)
					push((int)pop() % (int)t1);
				else
					printf("Error: division by zero\n");
				break;
			case '\n':
				printf("%.8g\n", pop());
				break;
			default:
				printf("Error: unknown command \"%s\"\n", s);
				break;
		}
	}
	return 0;
}

void clear()
{
	printf("%.8g\n", pop()); //Print the top value in the stack before clearing it
	while(sp != 0)
		val[sp--] = 0.0;
	sp++;
}

double pop()
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

int getop(char s[])
{
	int i, c;
	
	while((s[0] = c = getcha()) == ' ' || c == '\t')
		;
		
	s[1] = '\0';
	i = 0;
	
	if(!isdigit(c) && c != '.' && c != '-')
		return c;

	if(c == '-') {
		if(!isdigit(s[++i] = c = getcha())) {
			s[i] = '\0';
			if(c != EOF)
				ungetcha(c);
			return s[0];
		}
		while(isdigit(s[++i] = c = getcha()))
			;
	}
	
	if(isdigit(c))
		while(isdigit(s[++i] = c = getcha()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getcha()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetcha(c);
	return NUMBER;
}

int getcha()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetcha(int c)
{
	if(bufp >= BUFSIZE)
		printf("Ungetch: too many chars\n");
	else
		buf[bufp++] = c;
}
