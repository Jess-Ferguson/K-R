/* entab.c - Program that replaces white space characters with the correct number of tabs and blanks to achieve the same spacing
 * - i - Current position in the array
 * - j - Number of blanks detected after the first blank is found
 * - k - Total number of spaces required to achieve the current cursor position
 * - l - Number of spaces requried to reach the next tab stop - strictly redundant but improves readability (and saves a few calculations)
 */
#include <stdio.h>
#define MAXLEN 1024
#define TAB_WIDTH 8 // Assume we aren't being heretics

int get_line(char s[], int lim);

int main()
{
	int len, i, k, j, l;
	char line[MAXLEN];
	
	while((len = get_line(line, MAXLEN)) > 0) {
		for(i = 0, k = 1; line[i] != '\0'; i++, k++) {
			l = TAB_WIDTH - (k % TAB_WIDTH);
			if(line[i] == ' ') {
				for(j = 1; j < l; j++)
					if(line[i + j] != ' ')
						break;
				
				if(j == l) { // If only spaces were detected
					putchar('\t');
					i += l;
					k += l;
				} else if(line[i + j] == '\t') { // If spaces and tabs were detected
					putchar('\t');
					i += j;
					k += j;
				} else { // If spaces and non whitespace chars were detected
					putchar(line[i]);
				}
			} else {
				if(line[i] == '\t')
					k += l;
				putchar(line[i]);
			}
		}
	}
	
	return 0;
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
