#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINES 4096
#define MAXLEN 128

int readlines(char line_ptr[][MAXLEN], int lim_lines, int lim_len);
int getlinep(char *s, int lim);
int isnum(char *str);

int main(int argc, char *argv[])
{
	int lines;
	int i;
	int tail_len = 10;
	char lineptr[MAXLINES][MAXLEN];

	argv++;

	while(argc-- > 2 && **argv == '-') { 
		switch(*(*argv++ + 1)) {
			case 'n':
				printf("%s\n", *argv);
				if(isnum(*argv))
					tail_len = atoi(*argv);
				break;
			default:
				break;
		}
	}

	if((lines = readlines(lineptr, MAXLINES, MAXLEN)) >= 0) {
		tail_len = (lines >= tail_len) ? tail_len : lines;
		for(i = tail_len; i > 0; i--)
			printf("%s\n", lineptr[lines - i]);
		return 0;
	} else {
		printf("Error: Input too big!\n");
		return -1;
	}
}

int readlines(char line_ptr[][MAXLEN], int lim_lines, int lim_len)
{
	int len;
	int nlines = 0;
	
	while((len = getlinep(line_ptr[nlines], lim_len)) > 1) {
		if(nlines >= lim_lines)
			return -1;	
		line_ptr[nlines++][len - 1] = '\0'; 
	}
	return nlines;
}

int getlinep(char *s, int lim)
{
	int i;
	
	for(i = 0; i < lim - 1 && (*s = getchar()) != EOF && *s != '\n'; i++, s++)
		;
	
	if(*s == '\n') {
		i++;
		s++;
	}
	
	*s = '\0';
	
	return i;
}

int isnum(char *str)
{
	unsigned int len	= 0;
	unsigned int i		= 0;
	
	while(str[len] != '\0')
		len++;
	
	if(str[i] == '-')
		i = 1;
	
	while((str[i] - '0' <= 9 && str[i] - '0' >= 0) || str[i] == '.'	)
		i++;
	
	if(i == len)
		return 1;
		
	return 0;
}