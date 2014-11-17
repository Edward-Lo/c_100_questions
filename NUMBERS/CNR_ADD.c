#include <stdio.h>
#include <stdlib.h>

unsigned long cnr(int n, int r)
{
	int *p = (int *)(malloc((r+1) * sizeof(int)));
	int i, j;
	unsigned long result;
	for(i = 0; i <= r; i++)
		p[i] = 1;
	for(i = 1; i <= n - r; i++)
		for(j = 1; j <= r; j++)
			p[j] += p[j-1];

	result = p[r];
	free(p);
	return result;
}

int main(void)
{
	int n, r;
	printf("Please input n / r: ");
	scanf("%d%d", &n, &r);
	printf("The result is %d\n", cnr(n, r));
}

