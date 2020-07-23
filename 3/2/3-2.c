#include <stdio.h>
void escape(char s[], char t[]);

int main()
{
	char s[] = "This\tis\nA test\nstring\n";
	int i;
	
	for(i = 0; s[i] != '\0'; i++)
		if(s[i] == '\t' || s[i] == '\n')
			i++;
	char t[i];
	
	escape(s, t);
	printf("The string with escape sequences removed appears as:\n\"%s\"\n", t);
	
	return 0;
}

void escape(char s[], char t[])
{
	int i, j;
	
	for(j = i = 0; s[i] != 0; i++, j++) {
		switch(s[i]) {
			case '\t':
				t[j++] = '\\';
				t[j] = 't';
				break;
			case '\n':
				t[j++] = '\\';
				t[j] = 'n';
				break;
			default:
				t[j] = s[i]; 
		}
	}
}
