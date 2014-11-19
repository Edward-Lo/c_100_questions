#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define len(x) sizeof(x) / sizeof(x[0])

int x[] = {1, 3, 7, 9, 15, 18, 24, 35, 79, 101, 184, 300, 464, 570, 894, 100, 1111, INT_MAX, INT_MAX, INT_MAX};

void bound(int *p, int *left, int *right, int v)
{
	int len = 1;
	*left = 0, *right = 1;
	while(!(p[*left] <= v && v < p[*right])) {
		*left = *right;
		len <<= 1;
		*right += len;
	}

	*right--;
}

int binary_search(int *p, int left, int right, int v)
{
	int middle;

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
	int i, n, found = 0;
	int start, end;

	printf("Please input a # you wanna search: ");
	scanf("%d", &n);

	bound(x, &start, &end, n);
	if((i = binary_search(x, start, end, n)) > 0)
		printf("We found it @ x[%d] = %d\n", i, x[i]);
	else
		printf("No solution\n");

	return 0;
}
