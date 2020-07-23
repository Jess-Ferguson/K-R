#include <stdio.h>

void str_cat(char *base, char *cat);

int main()
{
	char first[100] = "This is a test string";
	char second[] = " and this is a second bit";
	
	printf("%s\n", first);
	str_cat(first, second);
	printf("%s\n", first); 
	return 0;
}

void str_cat(char *base, char *cat)
{
	int i, j;
	
	for(i = 0; *(base + i) != '\0'; i++)
		;
	
	for(j = 0; *(cat + j) != '\0'; j++)
		*(base + i + j) = *(cat + j);
}

/* 	Pro tip dumbshit, you can increment the pointers as it's PASS BY VALUE
	- No need for extra variables
	- I was right about the basic princible however, although optimising out the checks in the loops should have been obvious
	- That said, I am drunk
	- Oh well

void str_cat(char *base, char *cat)
{
	while(*++base)
		;
	while(*base++ = *cat++)
		;
}

*/
