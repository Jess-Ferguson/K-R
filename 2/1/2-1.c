#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main()
{
	printf("%d to %d is the range of a char\n", CHAR_MIN, CHAR_MAX);
	printf("%d to %d is the range of an int\n", INT_MIN, INT_MAX);
	printf("%d to %d is the range of a short\n", SHRT_MIN, SHRT_MAX);
	printf("%ld to %ld is the range of a long\n", LONG_MIN, LONG_MAX);
	printf("%d is the max value for an unsigned char\n", UCHAR_MAX);
	printf("%u is the max value for an unsigned int\n", UINT_MAX);
	printf("%d is the max value for an unsigned short\n", USHRT_MAX);
	printf("%lu is the max value for an unsigned long\n", ULONG_MAX);
	printf("%f is the max value for a float\n", FLT_MAX);
	printf("%g is the smallest non-zero value for a float\n", FLT_EPSILON);
	printf("%f is the max value for a double\n", DBL_MAX);
	printf("%g is the smallest non-zero value for a float\n", DBL_EPSILON);
	return 0;
}
