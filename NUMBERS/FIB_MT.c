#include <stdio.h>

void matrix_power(unsigned long a, unsigned long b,
						   unsigned long c, unsigned long d, int n,
						   unsigned long *aa, unsigned long *bb,
						   unsigned long *cc, unsigned long *dd)
{
	unsigned long xa, xb, xc, xd;
	if(n == 1)
		*aa = a, *bb = b, *cc = c, *dd = d;
	else if(n & 0x1UL) {
		matrix_power(a, b, c, d, n-1, &xa, &xb, &xc, &xd);
		*aa = a * xa + b * xc;
		*bb = a * xb + b * xd;
		*cc = c * xa + d * xc;
		*dd = c * xb + d * xd;
	}
	else {
		matrix_power(a, b, c, d, n/2, &xa, &xb, &xc, &xd);
		*aa = xa * xa + xb * xc;
		*bb = xa * xb + xb * xd;
		*cc = xc * xa + xd * xc;
		*dd = xc * xb + xd * xd;
	}
}

unsigned long fibonacci(int n)
{
	unsigned long a, b, c, d;

	if(n <= 2)
		return 1;
	else
		matrix_power(1UL, 1UL, 1UL, 0UL, n-2, &a, &b, &c, &d);
	
	return a+b;
}

int main(void)
{
	int n;
	printf("Please input the # of fibonacci:");
	scanf("%d", &n);
	printf("The result is %d\n", fibonacci(n));
}
