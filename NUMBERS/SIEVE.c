#include <stdio.h>
#include <stdlib.h>
#define DELETED 1
#define KEPT	0

int get_prime(int *p, int n)
{
	int count = 1;
	int i, j, prime;
	// init
	for(i = 0; i < n; i++)
		p[i] = KEPT;
	
	for(i = 0; i < n; i++)
		if(p[i] == KEPT) {
			prime = 2 * i + 3;	
			count++;
			for(j = prime + i; j < n; j += prime)
				p[j] = DELETED;
		}

	return count;
}

int main(void)
{
	int i, n, count;
	int *p;
	printf("Please input a # (0 <= # <= 200):");
	scanf("%d", &n);
	if(n < 0 || n > 200)
		return -1;
	p = (int *)malloc(n * sizeof(int));
	get_prime(p, n);
	printf("   2 ");
	count = 1;
	for(i = 0; i < n; i++) {
		if(p[i] == KEPT) {
			printf("%4d ", i * 2 +3);
			count++;
			if(!(count % 10))
				printf("\n");
		}
	}

	free(p);
	return 0;
}
