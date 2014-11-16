#include <stdio.h>
#include <stdlib.h>

unsigned long recursive_power(unsigned long m, unsigned long n)
{
	unsigned long tmp;
	if(n == 0)
		return 1;
	else if(n % 2)
		return m * recursive_power(m, n - 1);
	else {
		tmp = recursive_power(m, n/2);
		return tmp * tmp;
	}
}

int main(void)
{
	int m, n;
	printf("Please input 2 # to compute m power of n: ");
	scanf("%d%d", &m, &n);
	if(m < 0 || n < 0)
		return -1;
	printf("Result %d", recursive_power(m, n));
	return 0;
}
