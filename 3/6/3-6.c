#include <stdio.h>
#define MAX_LEN 1024
void itoa(int n, char s[], int min_width, unsigned int str_len);
void reverse(char s[]);

int main()
{
	char s[MAX_LEN];
	itoa(-2147483648, s, 12, MAX_LEN);
	printf("%s\n", s);

	return 0;
}

void itoa(int n, char s[], int min_width, unsigned int str_len)
{
	int sign, i;
	if((sign = n) > 0)
		n = -n;
	i = 0;
	do {
		s[i++] = -(n % 10) + '0';
	} while(-(n /= 10) > 0);
	
	if(sign < 0)
		s[i++] = '-';
		
	while(i < str_len && i < min_width)
		s[i++] = ' ';
		
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i, j, k;
	
	for(i = 0; s[i] != '\0'; i++)
		;
	i--;
	
	for(j = 0; j <= i/2; j++) {
		k = s[j];
		s[j] = s[i - j];
		s[i - j] = k;
	}
}
