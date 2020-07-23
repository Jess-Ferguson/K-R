#include "compare.h"

int dircmp(const char * s1, const char * s2)
{
	while(*s1 != '\0' && *s2 != '\0') {
		if(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1)) {
			s1++;
			continue;
		}
	
		if(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2)) {
			s2++;
			continue;
		}

		if(*s1++ != *s2++)
			break;
	}

	return *s1 - *s2;
}

int foldcmp(const char * s1, const char * s2)
{
	while(*s1 != '\0' && *s2 != '\0' && (tolower(*s1++) == tolower(*s2++)))
		;

	return tolower(*s1) - tolower(*s2);
}

int folddircmp(const char * s1, const char * s2)
{
	while(*s1 != '\0' && *s2 != '\0') {
		if(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1)) {
			s1++;
			continue;
		}
	
		if(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2)) {
			s2++;
			continue;
		}
			
		if(tolower(*s1++) != tolower(*s2++))
			break;
	}

	return tolower(*s1) - tolower(*s2);
}

int numcmp(const char * s1, const char * s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	return (v1 < v2) ? -1 : (v2 > v1) ? 1 : 0;
}

int dircmpqsort(const void * s1, const void * s2)
{
	return dircmp(*(char * const *) s1, *(char * const *) s2);
}

int foldcmpqsort(const void * s1, const void * s2)
{
	return foldcmp(*(char * const *) s1, *(char * const *) s2);
}

int folddircmpqsort(const void * s1, const void * s2)
{
	return folddircmp(*(char * const *) s1, *(char * const *) s2);
}

int numcmpqsort(const void * s1, const void * s2)
{
	return numcmp(*(char * const *) s1, *(char * const *) s2);
}

int strcmpqsort(const void * s1, const void * s2)
{
	return strcmp(*(char * const *) s1, *(char * const *) s2);
}