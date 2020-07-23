#include <stdio.h>

#define print_str(x, y) printf(#x " = %s\n" #y " = %s\n", x, y)
#define print_flt(x, y) printf(#x " = %g\n" #y " = %g\n", x, y)
#define print_chr(x, y) printf(#x " = %c\n" #y " = %c\n", x, y)
#define swap(t, x, y) { t temp = x; x = y; y = temp; } (void)(0) /* Needs block structure so temp can be redefined on subsequent calls, needs the no-op to prevent other issues */

int main()
{
	char *a = "test";
	char *b = "string";
	float c = 12.345;
	float d = 67.890;
	char e = 'r';
	char f = 'q'; 
	
	print_str(a, b);
	print_flt(c, d);
	print_chr(e, f);
	swap(char *, a, b);
	swap(float, c, d);
	swap(char, e, f);
	print_str(a, b);
	print_flt(c, d);
	print_chr(e, f);
	
	if(1){
		swap(char *, a, b);
	} else if(0) {
		swap(float, c, d);
	}
	
	return 0;
}
