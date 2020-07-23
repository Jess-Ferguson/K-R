#include <stdio.h>

int squeeze(char s1[], char s2[]);

int main()
{
	char s1[] = "This is a test string";
	char s2[] = "ae";
	int pos;
	
	printf("%s\n", s1);
	printf("Removing chars \"%s\"\n", s2);
	pos = squeeze(s1, s2);
	printf("%s\nFirst removal at position %d\n", s1, pos);
		
	return 0;
}

int squeeze(char s1[], char s2[])
{
	int i, j, k, pos;
	
	pos = -1;
	
	for(i = j = 0; s1[i] != '\0'; i++) {
		for(k = 0; s2[k] != '\0'; k++)
			if(s1[i] == s2[k]) {
				if(pos == -1)
					pos = i;
				break;
			}

		if(s2[k] == '\0')
			s1[j++] = s1[i];
	}
	
	s1[j] = '\0';
	
	return pos;
}
