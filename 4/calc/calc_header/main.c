#include <stdlib.h>
#include "calc.h"
#define MAXOP 128

extern int sp;
extern int cur_var;
extern double vars[];
extern double val[];

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
