#include <stdio.h>

#define MAX_LEN 1024
void itob(long long n, char s[], int b);
void reverse(char s[]);

int main()
{
	char s[MAX_LEN];
	long x = -1234567;
	int b = 21;
	itob(x, s, b);
	printf("%ld in base %d is %s\n", x, b, s);
	
	return 0;
}

void itob(long long n, char s[], int b)
{
	char c;
	long long sign, mod;
	unsigned int i;
	
	i = 0;
	
	if(b > 62 || b < 2) {
		s[0] = '\0';
		return;
	}
	
	if((sign = n) > 0)
		n = -n;
	
	do {
		mod = -(n % b);
		if(mod > 35)
			c = 'a' - 36;
		else if(mod > 9)
			c = 'A' - 10;
		else
			c = '0';
		s[i++] = mod + c;
	} while(-(n /= b) > 0);
	
	if(sign < 0)
		s[i++] = '-';
		
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i, j, k;
	
	i = strlen(s) - 1;
	
	for(j = 0; j <= i/2; j++) {
		k = s[j];
		s[j] = s[i - j];
		s[i - j] = k;
	}
}
