#include <stdio.h>
#include <stdlib.h>

int get_factor(int *factor, int *exp, int n)
{
	int i, j, count = 0;
	int is_prime;
	for(i = 0; n > 1 && !(n % 2); n /= 2, i++);
	if(i)
		factor[0] = 2, exp[0] = i, count++; 

	for(i = 3; i <= n; i+=2) {
		is_prime = 1;
		for(j = 0; j < count; j++)
			if(!(i % factor[j])) {
				is_prime = 0;
				break;
			}
		// for practice 2
		if(!is_prime)
			continue;
		for(j = 0; n > 1 && !(n % i); n /= i, j++);
		if(j)
			factor[count] = i, exp[count++] = j;
	} 

	return count;
}

int main(void)
{
    int i, n, count;
    int *x, *y;
    printf("Please input a # to get its factors:");
    scanf("%d", &n);
    x = (int *)malloc((n) * sizeof(int));
    y = (int *)malloc((n) * sizeof(int));
    count = get_factor(x, y, n);
    for(i = 0; i < count; i++) {
		printf("%d(%d)", x[i], y[i]);
    }
	printf("\n");

    free(x);
    free(y);
	return 0;
}
