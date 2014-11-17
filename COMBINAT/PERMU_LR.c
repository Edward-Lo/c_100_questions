#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) { int t; t = x; x = y; y = t; }

void permu_lr(int n)
{
	int *p = (int *)malloc(n * sizeof(int));
	int i, left, right, last;
	for(i = 0; i < n; i++)
		p[i] = i + 1;
	
	while(1) {
		printf("{ ");
		for(i = 0; i < n; i++)
			printf("%d ", p[i]);
		printf("}\n");

		// Fischer-Kruse way
		for(last = n - 2; last >= 0 && p[last] > p [last + 1]; last--);
		if(last < 0)
			break;
		for(i = n - 1; p[i] < p[last]; i--);
		SWAP(p[last], p[i]);
		for(left = last + 1, right = n - 1; left < right; left++, right--)
			SWAP(p[left], p[right]);
	}

	free(p);
}

int main(void)
{
	int n;
	printf("Please input a # to get its permutations: ");
	scanf("%d", &n);
	permu_lr(n);
	return 0;
}
