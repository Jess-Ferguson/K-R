#ifndef LINES_H
#define LINES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128

int getlinep(char *s, int lim);
int readlines(char * line_ptr[], int max_lines);
void writelines(char *line_ptr[], int nlines, bool reverse);

#endif