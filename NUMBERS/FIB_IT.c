#include <stdio.h>

unsigned long fibonacci(int n)
{
	int f1 = 1, f2 = 1, f = 1;
	int i;
	for(i = 3; i <= n; i++) {
		f = f1 + f2;
		f1 = f2;
		f2 = f;
	}

	return f;
}

int main(void)
{
	int n;
	printf("Please input the # of fibonacci:");
	scanf("%d", &n);
	printf("The result is %d\n", fibonacci(n));
}
