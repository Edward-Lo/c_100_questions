#include <stdio.h>
int z[] = {1,2,2,3,3,3,4,5,5,5,5,5,6};
int longest_plateau(int *x, int n)
{
	int length = 1;
	int pos = 0;
	int *p1 = x, *p2 = x;
	int i;
	for(i = 1; i < n; i++) {
		if(x[i] == x[i - length]) {		
			pos = i - length;
			length++;
		}
	}

	// for pracetice 3
	while(p2 < x + n) {
		if(*p1 == *p2)
			p2++;
		else {
			printf("Subarray {%d} length = %d\n", *p1, p2 - p1);
			p1 = p2;
		}
	}
	printf("Subarray {%d} length = %d\n", *p1, p2 - p1);
	
	// for practice 2
	printf("The longest subarray starts @ x[%d] = %d\n", pos, x[pos]);
	return length;
}

int main(void)
{
	printf("The longest len is %d\n", longest_plateau(z, sizeof(z) / sizeof(z[0])));
	return 0;
}
