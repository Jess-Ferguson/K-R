#include <stdio.h>
#include <stdlib.h>
void expand(char s[], char t[]);

int main()
{
	char s[] = "a-z-a";
	int i, j;
	
	for(i = j = 0; s[i] != '\0'; i++, j++)
		if(s[i] == '-' && s[i + 1] != '\0' && i > 0)
			j += abs(s[i - 1] - s[i + 1]);
	
	char t[j];
	printf("s = \"%s\"\n", s);
	expand(s, t);
	printf("%s\n", t);
	return 0;
}

void expand(char s[], char t[])
{
	int i, j, inc;
	char k;
	
	for(i = j = 0; s[i] != '\0'; i++)
		if(s[i] == '-' && s[i + 1] != '\0' && i > 0) {
			if(s[i - 1] == s[i + 1])
				inc = 1;
			else
				inc = (s[i + 1] - s[i - 1]) / abs(s[i - 1] - s[i + 1]);
			for(k = s[i - 1]; k != s[i + 1] + inc; k += inc) {
				t[j++] = k;
				if(i > 1 && j > 1 && t[j - 1] == t[j - 2] && s[i - 1] != s[i - 2])
					j--; 
			}
		} else if(s[i + 1] != '-' && s[i - 1] != '-'){
			t[j++] = s[i];
		}
		
	t[j] = '\0';
}
