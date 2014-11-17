#include <stdio.h>
#include <math.h>
void given_sum(int n)
{
	int i = 0, j, sum = 0, count = 0;
	for(i = 1; sum < n; sum += i, i++);

	for(j = 1, i--; j <= n/2;) {
		if(sum > n)
			sum -= j++;
		else { 
			if(sum == n)
				printf("%d + ... + %d = %d\n", j, i, n), count++;
			sum += ++i;
		}
	}

	if(!count)
		printf("There is no solution for %d\n", n);
}

// for practice 3
void given_mul(int n)
{
	int i = 0, j, sum = 1, count = 0;
	int sqrt_n = floor(sqrt((double)n) + 0.5);
	for(i = 1; sum < n; sum *= i, i++) ;

	for(j = 2, i--; j <= sqrt_n;) {
		if(sum > n)
			sum /= j++;
		else { 
			if(sum == n)
				printf("%d x ... x %d = %d\n", j, i, n), count++;
			sum *= ++i;
		}
	}

	if(!count)
		printf("There is no solution for %d\n", n);
}

int main(void)
{
	int n;
	printf("Please input a #: ");
	scanf("%d", &n);
	//given_sum(n);
	given_mul(n);
	return 0;
}
