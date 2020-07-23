#include <string.h>
#include "calc.h"

extern int sp;
extern int cur_var;
extern double val[];
extern double vars[];

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

void comm_handle(char s[]) /* Secondary control structure */
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
			"#########################################################################\n\n"
	);
		getch();
}
