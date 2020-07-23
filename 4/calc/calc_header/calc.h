#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UNSET -1
#define NUMBER 0
#define COMMAND 1
#define VAR_NUM 27
#define MAXVAL 128

int getop(char s[]);

double pop(void);
void push(double n);

int getch(void);
void ungetch(int c);

void clear(void);
void comm_handle(char s[]);
void help(void);
void print(void);
