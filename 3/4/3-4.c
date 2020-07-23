#include <stdio.h>
#include <string.h>
void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
	char s[20];
	itoa(-2147483648, s);
	printf("s = %s\n", s);
	itoa(2147483647, s);
	printf("s = %s\n", s);
	int x = -2147483648;
	int y;
	scanf("%d", &y);
	x /= y;
	printf("x = %d", x);
}

void itoa(int n, char s[])
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
	s[i] = '\0';
	reverse(s);	
}

void reverse(char s[])
{
	int i, j, k, newl;
	
	for(i = 0; s[i] != '\0'; i++)
		;
	
	if(s[--i] == '\n') {
		--i;
		newl = 1;
	} else {
		newl = 0;
	}
	
	for(j = 0; j <= i/2; j++) {
		k = s[j];
		s[j] = s[i - j];
		s[i - j] = k;
	}
	
	if(newl)
		s[++i] = '\n';
}
