#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_prime(int *p, int n)
{
	int i, j, count = 0;
	int is_prime;
	double sqrt_i;
	if(n >= 1)
		p[0] = 2, count = 1;
	
	for(i = 3; count < n; i+=2) {
		is_prime = 1;
		sqrt_i = floor(sqrt((double) i) + 0.5);
		for(j = 0; p[j] <= sqrt_i && j < count; j++)
			if(i % p[j] == 0) {
				is_prime = 0;
				break;
			}
		if(is_prime)
			p[count++] = i;
	}
}

int get_prime2(int *p, int n)
{
	int i, j, count = 0, gap = 2;
	int is_prime;
	double sqrt_i;
	if(n >= 1)
		p[0] = 2, count = 1;
	if(n >= 2)
		p[1] = 3, count = 2;
	if(n >= 3)
		p[2] = 5, count = 3;
	
	for(i = 7; count < n; i+=gap) {
		gap = 6 - gap;
		is_prime = 1;
		sqrt_i = floor(sqrt((double) i) + 0.5);
		for(j = 0; p[j] <= sqrt_i && j < count; j++)
			if(i % p[j] == 0) {
				is_prime = 0;
				break;
			}
		if(is_prime)
			p[count++] = i;
	}
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
	count = get_prime2(p, n);
	for(i = 0; i < n; i++) {
		if(i && !(i % 10))
			printf("\n");
		printf("%4d ", p[i]);
	}

	free(p);
	return 0;
}
