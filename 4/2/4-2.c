#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double atofl(char s[]);

int main()
{
	int i;
	double y;
	
	for(i = 0; i < 1000000; i++) {
		y = atofl("123.45E-18");
	}
	printf("%.25f\n", y);
	
	return 0; 
}

double atofl(char s[])
{
	unsigned int i;
	long exp;
	int sign, exsign;
	double val, power;
	
	for(i = 0; isspace(s[i]); i++)
		;
	
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10 * val + (s[i] - '0');
		
	if(s[i++] == '.')
		for(power = 1.0; isdigit(s[i]); i++) {
			val = 10 * val + (s[i] - '0');
			power *= 10;
		}
	
	val /= power; // Precision is improved by doing this operation before modifying val further
		
	if(s[i] == 'E' || s[i] == 'e') {
		exsign = (s[++i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-')
			i++;
			
		for(exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');
			
		while(exp-- != 0)
			val *= (exsign > 0) ? 10 : 0.1;
	}
	return sign * val;
}

