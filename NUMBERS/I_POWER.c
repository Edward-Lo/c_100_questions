#include <stdio.h>
#include <stdlib.h>

unsigned long iterative_power(unsigned long m, unsigned long n)
{
	unsigned long tmp = 1;
	while(n > 0) {
		if(n & 0x1UL)
			tmp *= m;
		m *= m;
		n >>= 1;
	}

	return tmp;
}

int main(void)
{
	int m, n;
	printf("Please input 2 # to compute m power of n: ");
	scanf("%d%d", &m, &n);
	if(m < 0 || n < 0)
		return -1;
	printf("Result %d", iterative_power(m, n));
	return 0;
}
