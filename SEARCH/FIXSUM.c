#include <stdio.h>
#include <stdlib.h>

#define len(x) sizeof(x) / sizeof(x[0])

int p[] = {3, 7, 2, 4};
int q[] = {1, 5, 2, 3};

int cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	return x - y;
}

int binary_search(int *p, int n, int v)
{
	int left = 0, right = n - 1, middle;

	while(left <= right) {
		middle = (left + right) / 2;
		if(p[middle] == v)
			return middle;
		if(p[middle] > v)
			right = middle - 1;
		else
			left = middle + 1;
	}

	return -1;
}

int main(void)
{
	int i, j, n, count = 0;
	int len_p = len(p);
	int len_q = len(q);
	qsort(p, len(p), sizeof(int), cmp);
	printf("Please input a # you wanna search: ");
	scanf("%d", &n);
	for(i = 0; i < len_q; i++) {
		j = binary_search(p, len_p, n - q[i]); 
		if(j >= 0) {
			count++;
			printf("p[%d] + q[%d] = %d + %d = %d\n", j, i, p[j], q[i], n);
		}
	}

	if(!count)
		printf("Sorry, no solution\n");
	return 0;
}
