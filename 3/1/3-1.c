#include <stdio.h>
#define MAX_ELEMENT 1250000

int bin_search(int *str, int tgt, int max);

int main()
{
	int str[MAX_ELEMENT];
	int c, i, len;
	
	for(i = 0; i < MAX_ELEMENT; i++)
		str[i] = i;
	
	len = sizeof(str)/sizeof(str[0]) - 1;
	
	c = 1;
	
	int pos;
	for(i = 0; i < MAX_ELEMENT; i++)
		pos = bin_search(str, c, len);
	
	if(pos >= 0)
		printf("%d is at element %d in the array\n", c, pos);
	else
		printf("%d was not found in the array\n", c);
	
	return 0;
}

int bin_search(int *str, int tgt, int max)
{
	int min = 0;
	int mid = max / 2;

	while(max >= min) {
		if(str[mid] > tgt)
			max = mid - 1;
		else
			min = mid + 1;
		mid = (max + min) / 2;
	}
	
	return str[mid] == tgt ? mid : -1;
}
