#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 4096
#define MAXLEN 128

void writelines(char line_ptr[][MAXLEN], int lim);
int readlines(char line_ptr[][MAXLEN], int lim_lines, int lim_len);
int getlinep(char *s, int lim);
//void quicksort(char v[][MAXLEN], int left, int right);
//void swap(char v[][MAXLEN], int i, int j);

int main()
{
	int lines;
	char lineptr[MAXLINES][MAXLEN];

	if((lines = readlines(lineptr, MAXLINES, MAXLEN)) >= 0) {
		// quicksort(lineptr, 0, lines - 1);
		writelines(lineptr, lines);
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

void writelines(char line_ptr[][MAXLEN], int lim)
{
	int i;
	
	for(i = 0; i < lim; i++)
		printf("%s\n", line_ptr[i]);
}

/*void quicksort(char v[][MAXLEN], int left, int right)
{
	int i, last;
	
	if(left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for(i = left + 1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}

void swap(char v[][MAXLEN], int i, int j)
{
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
} */

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
