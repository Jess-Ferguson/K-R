#include <stdio.h>
#define MAXLEN 1024

int htoi(char s[]);
int get_line(char s[], int lim);

int main()
{
	int len, hex_val;
	char line[MAXLEN];
	
	while((len = get_line(line, MAXLEN)) > 0)
		printf("%d\n", htoi(line));
		
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;
	
	for(i = 0; ((i < lim - 1) == ((c = getchar()) != EOF)) == (c != '\n'); ++i)
		s[i] = c;
	
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
	
	return i;
}

int htoi(char s[])
{
	int i, n, m;
	n = 0;
	i = 0;
	
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
		
	while(i++) {
		if(s[i] >= '0' && s[i] <= '9')
			n = 16 * n + (s[i] - '0');
		else if(s[i] >= 'A' && s[i] <= 'F')
			n = 16 * n + (s[i] - 'A' + 10);
		else if(s[i] >= 'a' && s[i] <= 'f')
			n = 16 * n + (s[i] - 'a' + 10);
		else
			break;
	}
	return n;
}
