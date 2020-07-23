#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1024

#define EXEC_SUCCESS 0
#define MATH_ERROR 1

int isnum(char *str);
int isop(char c);

bool fp = false;

int main(int argc, char *argv[]) /* Tidy up this shit show */
{
	float nums[MAX_LEN];
	char ops[MAX_LEN];
	int num_val;
	int ops_val;
	double result;

	if(argc == 1) {
		printf("Error: Too few arguments!\n");
		return -1;
	}

	argv++;

	for(num_val = 0; argc-- > 0 && isnum(*argv) && num_val < MAX_LEN; num_val++)
		nums[num_val] = atoi(*(argv++));

	for(ops_val = 0; argc-- > 0 && isop(**argv) && ops_val < MAX_LEN; ops_val++)
		ops[ops_val] = **(argv++);

	printf(fp ? "%f" : "%.0f", result = nums[--num_val]);

	for(int i = 0; num_val > 0 && i < ops_val; i++, --num_val) {
		printf(fp ? " %c %f" : " %c %.0f", ops[i], nums[num_val - 1]);
		switch(ops[i]) {
			case '+':	
				result += nums[num_val - 1];
				break;
			case '-':
				result -= nums[num_val - 1];
				break;
			case 'x':
				result *= nums[num_val - 1];
				break;
			case '/':
				if(!nums[num_val - 1]) {
					fprintf(stderr, "\nError: division by zero!\n");
					return MATH_ERROR;
				}

				result /= nums[num_val - 1];
				break;
			default:
				break;
		}
	}

	if(result != (int)result) /* Just in case the result is non-integer */
		fp = true;

	printf(fp ? "\nResult: %f\n" : "\nResult: %0.f\n", result);

	return EXEC_SUCCESS;
}

int isnum(char *str)
{
	unsigned int len	= 0;
	unsigned int i		= 0;
	
	while(str[len] != '\0')
		len++;
	
	if(str[0] == '-') {
		if(len == 1) 
			return 0;

		i = 1;
	}
	
	while((str[i] - '0' <= 9 && str[i] - '0' >= 0) || (str[i] == '.' && (fp = true))) /* Hack to check if any inputs are floating point */
		i++;
	
	if(i == len)
		return 1;
		
	return 0;
}

int isop(char c)
{
	return ((c == 'x') || (c == '/') || (c == '+') || (c == '-'));
}