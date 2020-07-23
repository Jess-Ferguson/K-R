#include <ctype.h>
#include "calc.h"

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
		ungetch(c);
		return COMMAND;
	}
	
	if(!isdigit(c) && c != '.' && c != '-')
		return c;

	if(c == '-') {
		if(!isdigit(s[++i] = c = getch())) {
			s[i] = '\0';
			ungetch(c);
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
	ungetch(c);
	return NUMBER;
}
