#include <stdio.h>
void lower(char s[]);

int main()
{
	char s[] = "THIS is A test STRING";
	printf("%s\n", s);
	lower(s);
	printf("%s\n", s);
	return 0;
}

void lower(char s[])
{
	int i;
	for(i = 0; s[i] != '\0'; i++) {
		s[i] += (s[i] >= 'A' && s[i] <= 'Z') ? 'a' - 'A' : 0;
	}
}
