#ifndef COMP_H
#define COMP_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int dircmp(const char * s1, const char * s2);
int foldcmp(const char * s1, const char * s2);
int folddircmp(const char * s1, const char * s2);
int numcmp(const char * s1, const char * s2);

int dircmpqsort(const void * s1, const void * s2);
int foldcmpqsort(const void * s1, const void * s2);
int folddircmpqsort(const void * s1, const void * s2);
int numcmpqsort(const void * s1, const void * s2);
int strcmpqsort(const void * s1, const void * s2);

#endif