#include <stdio.h>
#include <stdlib.h>
#include "compare.h"
#include "lines.h"

#define MAXLINES 5000

#define DIRECTORY 1
#define FOLD 2
#define NUMERIC 4
#define REVERSE 8

char * line_ptr[MAXLINES];

int main(int argc, char *argv[])
{
	int nlines;
	int options;
	int (*comparison)(const void *, const void *);

	while(argc-- > 1 && **(++argv) == '-') {
		while(*(++*argv)) {
			switch(**argv) {
				case 'd':
					options |= DIRECTORY;
					break;
				case 'f':
					options |= FOLD;
					break;
				case 'n':
					options |= NUMERIC;
					break;
				case 'r':
					options |= REVERSE;
					break;
				default:
					break;
			}
		}
	}

	if(options & NUMERIC)
		comparison = numcmpqsort;
	else if(options & FOLD && options & DIRECTORY)
		comparison = folddircmpqsort;
	else if(options & FOLD)
		comparison = foldcmpqsort;
	else if(options & DIRECTORY)
		comparison = dircmpqsort;
	else
		comparison = strcmpqsort;

	#ifdef DEBUG
		printf(	"numeric sort is %sabled, output inversion is %sabled, line folding is %sabled, directory listing is %sabled\n", 
					options & NUMERIC ? "en" : "dis",
					options & REVERSE ? "en" : "dis",
					options & FOLD ? "en" : "dis",
					options & DIRECTORY ? "en" : "dis"
			);
		
		#ifdef STRING_1
		#ifdef STRING_2
			printf("Is \"%s\" equal to \"%s\" (strcmp)? %s\n", STRING_1, STRING_2, !strcmp(STRING_1, STRING_2) ? "TRUE" : "FALSE");
			printf("Is \"%s\" equal to \"%s\" (numcmp)? %s\n", STRING_1, STRING_2, !numcmp(STRING_1, STRING_2) ? "TRUE" : "FALSE");
			printf("Is \"%s\" equal to \"%s\" (dircmp)? %s\n", STRING_1, STRING_2, !dircmp(STRING_1, STRING_2) ? "TRUE" : "FALSE");
			printf("Is \"%s\" equal to \"%s\" (foldcmp)? %s\n", STRING_1, STRING_2, !foldcmp(STRING_1, STRING_2) ? "TRUE" : "FALSE");
			printf("Is \"%s\" equal to \"%s\" (folddircmp)? %s\n", STRING_1, STRING_2, !folddircmp(STRING_1, STRING_2) ? "TRUE" : "FALSE");
		#endif
		#endif
	#endif

	if((nlines = readlines(line_ptr, MAXLINES)) >= 0) {
		qsort((void **) line_ptr, nlines - 1, sizeof(char *), comparison);
		writelines(line_ptr, nlines, options & REVERSE);
		return 0;
	} else {
		fprintf(stderr, "Input too large to sort!\n");
		return -1;
	}
}