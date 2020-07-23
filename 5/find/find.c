// find.c - Find any lines in the input matching the pattern in the first argument that isn't an option. Options should include -n (line numbering) and -x (except, i.e. invert the output)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE 1024

int get_line(char s[], int lim);
int strindexp(char *s, char *t);

int main(int argc, char *argv[])
{
	bool except = false;
	bool numbering = false;
	char line[MAX_LINE];
	int line_no = 0;
	int found = 0;

	argv++;

	while(argc-- > 1 && **argv == '-') { 	/* Syntactically synonymous to *argv[0] */
		switch(*(*argv++ + 1)) {			/* Syntactically synonymous to (*argv++ + 1)[0] */
			case 'n':
				numbering = true;
				break;
			case 'x':
				except = true;
				break;
			default:
				break;
		}
	}

	if(argc < 1) {
		printf("Usage: find -n -x pattern\n");
	} else {
		/*printf(	"Pattern is \"%s\", numbering is %s, output inversion is %s\n", 
				*argv,
				except ? "enabled" : "disabled",
				numbering ? "enabled" : "disabled"
		); */
		while(get_line(line, MAX_LINE) > 0) {
			line_no++;
			if((strindexp(line, *argv) >= 0) != except) {
				if(numbering)
					printf("%d: ", line_no);
				printf("%s\n", line);
				found++;
			}
		}
	}

	return found;
}

int get_line(char s[], int lim)
{
	int c, i;
	
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if(i < lim - 1)
			s[i] = c;
				
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
	
	return i;
}

int strindexp(char *s, char *t)
{
	char *u, *v, *w;
	
	for(v = s; *s; s++) {
		for(u = s, w = t; *u == *w; u++, w++)
			;
		if(!*w)
			return s - v;
	}
	
	return -1;
}
