#include <stdio.h>

char strend(char *s, char *t);

int main()
{
	char *s1 = "string one";
	char *s2 = "test";
	char *s3 = "one";
	
	strend(s1, s2) ? printf("%s is at the end of %s\n", s2, s1) : printf("%s is not at the end of %s\n", s2, s1);
	strend(s1, s3) ? printf("%s is at the end of %s\n", s3, s1) : printf("%s is not at the end of %s\n", s3, s1);
	
	return 0;
}

char strend(char *s, char *t)
{
	char *v;
	
	for(;;) {
		v = t;
		while(*s != *t && *s)
			*s++;
			
		if(!*s)
			return 0;
		
		while(*s++ == *v++ && *s && *v)
			;
		
		if(!*s && !*v)
			return 1;
	}
}
