#include "lines.h"

int readlines(char *line_ptr[], int max_lines)
{
	int len, nlines;
	char line[MAX_LEN];
	nlines = 0;
	
	while((len = getlinep(line, MAX_LEN)) > 0) {
		if(nlines >= max_lines) {
			return -1;
		} else{
			if(!(line_ptr[nlines] = malloc(len + 1))) {
				fprintf(stderr, "Error: Could not allocate memory!\n");
				return -1;
			}
			strncpy(line_ptr[nlines++], line, len);
			line[0] = '\0';
		}
	}

	return nlines;
}

void writelines(char *line_ptr[], int nlines, bool reverse)
{
	if(reverse) {
		while(nlines-- > 0)
			printf("%s\n", line_ptr[nlines]);
	} else {
		while(nlines-- > 0)
			printf("%s\n", *line_ptr++);
	}
}

int getlinep(char *s, int lim)
{
	int i;
	
	for(i = 0; i < lim - 1 && (*s = getchar()) != EOF && *s != '\n'; i++, s++)
		;
	
	*s = '\0';
	
	return i;
}