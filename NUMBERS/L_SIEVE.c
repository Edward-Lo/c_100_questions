#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(x, y)	(x) < (y) ? (x) : (y)
#define NEXT(x)		x = next[x]
#define REMOVE(x)	{ next[previous[x]] = next[x]; \
					  previous[next[x]] = previous[x]; }
#define REMOVE2(x)	{ int i; \
					  i = MIN(x-1, next[x-1]); \
					  next[i] = next[x]; \
					  next[x] = i; }
#define INIT(n)		{ int i; \
					  for(i = 2; i <= n; i++) \
					  	previous[i] = i - 1, next[i] = i + 1; \
					  previous[2] = next[n] = 0; }
// for practice 1
#define INIT2(n)	{ int i; \
					  next[2] = 3; \
					  next[3] = 5; previous[3] = 2; \
					  for(i = 5; i <= n; i+=2) \
					  	previous[i] = i - 2, next[i] = i + 2; \
					  previous[2] = next[n] = 0; \
					  if(!(n % 2)) \
						next[n-1] = 0; }

int get_prime(int *next, int *previous, int n)
{
	int prime, fact, i, mult;
	int count = 0;
	int sqrt_n = floor(sqrt((double) n) + 0.5);
	INIT(n);
	
	for(prime = 2; prime <= sqrt_n; NEXT(prime))
		for(fact = prime; prime * fact <= n; NEXT(fact))
			for(mult = prime * fact; mult <= n; mult *= prime) {
				REMOVE2(mult);
				printf("==after==\n");
				printf("mult = %d, next[%d] = %d, next[%d] = %d\n", mult, mult, next[mult], mult-1, next[mult-1]);
			}

	return count;
}

int main(void)
{
    int i, n, count;
    int *x, *y;
    printf("Please input a # (0 <= # <= 200):");
    scanf("%d", &n);
    if(n < 0 || n > 200)
        return -1;
    x = (int *)malloc((n + 10) * sizeof(int));
    y = (int *)malloc((n + 10) * sizeof(int));
    get_prime(x, y, n);
    for(i = 2; i != 0; i = x[i]){
            count++;
			printf("%4d ", i);
            if(!(count % 10))
                printf("\n");
    }

    free(x);
    free(y);
	return 0;
}
