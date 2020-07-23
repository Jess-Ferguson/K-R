#include <stdio.h>
#include <string.h>

char *strngcpy(char *s, const char *ct, size_t n); /* Copy n characters of ct into s and return pointer to s. s is padded with '\0' if neccesary */
int strngcmp(const char *cs, const char *ct, size_t n); /* Compare at most n characters of two strings and return the difference between them, i.e. return 0 if they match */
char *strngcat(char *s, const char *ct, size_t n); /* Concatenate at most n characters of ct into s and return a pointer to s */

int main()
{
	char *s1 = "Test string";
	char s2[128];
	char *s3 = " addition";
	char *s4 = "This is a test string";
	int n = 12;
	int o = 9;
	
	printf("Copying the first %d characters of %s into s2...\n", n, s1);
	printf("Result: \"%s\"\n", strngcpy(s2, s1, n));
	
	printf("Comparing the first %d characters of \"%s\" and \"%s\"...\n", n, s1, s4);
	printf("Result: \"%d\"\n", strngcmp(s1, s4, n));
	
	printf("Concatenating the first %d characters of \"%s\" onto \"%s\"...\n", o, s3, s2);
	printf("Result: \"%s\"\n", strngcat(s2, s3, o));
	
	printf("\nCopying the first %d characters of %s into s2...\n", n, s1);
	printf("Result: \"%s\"\n", strncpy(s2, s1, n));
	
	printf("Comparing the first %d characters of \"%s\" and \"%s\"...\n", n, s1, s4);
	printf("Result: \"%d\"\n", strncmp(s1, s4, n));
	
	printf("Concatenating the first %d characters of \"%s\" onto \"%s\"...\n", o, s3, s2);
	printf("Result: \"%s\"\n", strncat(s2, s3, o));
	
	return 0;
}

char *strngcpy(char *s, const char *ct, size_t n)
{
	 size_t i;
	 
	 for(i = 0; i < n && *ct; i++)
	 	*s++ = *ct++;
	 
	 for(; i < n; i++)
	 	*s++ = '\0';
	 
	 *s = '\0';
	 
	 return s - n;
}

int strngcmp(const char *cs, const char *ct, size_t n)
{
	size_t i;
	
	for(i = 0; i < n && *cs == *ct; i++, ct++, cs++)
		;
	
	return *cs - *ct;
}

char *strngcat(char *s, const char *ct, size_t n)
{
	size_t i;
	size_t j;
	
	for(j = 0; *s; s++, j++)
		;
	
	for(i = 0; i < n && *ct; i++)
		*s++ = *ct++;
	
	*s = '\0';
	
	return s - i - j;
}
