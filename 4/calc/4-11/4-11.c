#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define UNSET -1
#define NUMBER 0
#define COMMAND 1
#define MAXVAL 100
#define BUFSIZE 100
#define VAR_NUM 27

int getop(char s[]);
int getch(void);
double pop(void);
void push(double n);
void ungetch(int c);
void clear(void);
void comm_handle(char s[]);
void help(void);
void print(void);

double val[MAXVAL];
double vars[VAR_NUM];
int sp = 0;
int bufp = 0;
int cur_var = UNSET;
static int buf = '\0';

int main(void)
{
	int type;
	double temp;
	char s[MAXOP];
	
	while((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case COMMAND:
				comm_handle(s);
				break;
			case '!':
				push(vars[VAR_NUM - 1]);
				break;
			case '=':
				if(cur_var != UNSET) {
					pop();
					vars[cur_var] = pop();
					printf("%c = %.8g\n", cur_var + 'a', vars[cur_var]);
					vars[VAR_NUM - 1] = vars[cur_var];
					cur_var = UNSET;
					getch();
				} else {
					printf("Error: No variable selected\n");
				}
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				temp = pop();
				push(pop() - temp);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				temp = pop();
				if(temp != 0.0)
					push(pop() / temp);
				else
					printf("Error: division by zero\n");
				break;
			case '%':
				temp = pop();
				if(temp != 0.0)
					push(fmod(pop(), temp));
				else
					printf("Error: division by zero\n");
				break;
			case '\n':
				if(sp > 0) {
					vars[VAR_NUM - 1] = val[sp - 1];
					printf("\t%.8g\n", pop());
				} else {
					printf("Error: bottom of stack reached\n");
				}
				break;
			default:
				printf("Error: Unsupported command \"%s\"\n", s);
				break;
		}
	}
	return 0;
}

void clear(void)
{
	do {
		val[sp--] = 0.0;
	} while(sp != 0);
	sp++;
	printf("Stack cleared\n");
}

void print(void)
{
	if(sp > 0) {
		vars[VAR_NUM - 1] = val[sp - 1];
		printf("\t%.8g\n", val[sp - 1]);
	} else {
		printf("Error: bottom of stack reached\n");
		getch();
	}
}

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

int getop(char s[])
{
	int i, c;
	
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	
	s[1] = '\0';
	i = 0;
	
	if(isalpha(c)) {
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c != '\0')
			buf = c;
		return COMMAND;
	}
	
	if(!isdigit(c) && c != '.' && c != '-')
		return c;

	if(c == '-') {
		if(!isdigit(s[++i] = c = getch())) {
			s[i] = '\0';
			if(c != '\0')
				buf = c;
			return s[0];
		}
		while(isdigit(s[++i] = c = getch()))
			;
	}
	
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != '\0')
		buf = c;
	return NUMBER;
}

int getch(void)
{
	char temp;
	
	if(buf != '\0') {
		temp = buf;
		buf = '\0';
		return temp;
	}

	return getchar();
}


void comm_handle(char s[])
{
	double t1, t2;
	
	if(!strcmp(s, "clear")) {
		clear();
	} else if(!strcmp(s, "print")) {
		print();
	} else if(!strcmp(s, "dup")) {
		t1 = pop();
		push(t1);
		push(t1);
	} else if(!strcmp(s, "swap")) {
		t1 = pop();
		t2 = pop();
		push(t1);
		push(t2);
	} else if(!strcmp(s, "help")) {
		help();
	} else if(!strcmp(s, "unset")) {
		for(t1 = 0; t1 < VAR_NUM; t1++)
			vars[(int)t1] = 0;
		getch();
	} else if(!strcmp(s, "cos")) {
		t1 = pop();
		push(cos(t1));
	} else if(!strcmp(s, "sin")) {
		t1 = pop();
		push(sin(t1));
	} else if(!strcmp(s, "tan")) {
		t1 = pop();
		push(tan(t1));
	} else if(!strcmp(s, "exp")) {
		t1 = pop();
		push(exp(t1));
	} else if(s[0] >= 'a' && s[0] <= 'z' && s[1] == '\0') {
		cur_var = s[0] - 'a';
		push(vars[s[0] - 'a']);
	} else {
		printf("Error: Unsupported command \"%s\"\n", s);
		getch();
	}
}

void help()
{
	printf(	"\n#########################################################################\n"
		"#\t\t\tReverse Polish calculator v0.1\t\t\t#\n"
		"#\t\t\t\t\t\t\t\t\t#\n"
		"# Standard rules for Reverse Polish notation apply\t\t\t#\n"
		"# List of commands:\t\t\t\t\t\t\t#\n"
		"#\t\t\t\t\t\t\t\t\t#\n"
		"# \"help\" - Show this menu\t\t\t\t\t\t#\n"
		"# \"print\" - Prints the top value in the stack without popping it\t#\n"
		"# \"clear\" - Clear the stack\t\t\t\t\t\t#\n"
		"# \"swap\" - Swap the top two elements in the stack\t\t\t#\n"
		"# \"dup\" - Duplicate the top element in the stack\t\t\t#\n"
		"#\t\t\t\t\t\t\t\t\t#\n"
		"# 26 variables are available in the form of the lower case letters\t#\n"
		"# as well as one unmodifiable variable (!) for the most recently\t#\n"
		"# printed value.\t\t\t\t\t\t\t#\n"
		"# Variables are set in the form: val char =\t\t\t\t#\n"
		"#########################################################################\n\n");
		getch();
}
