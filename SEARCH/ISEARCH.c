#include <stdio.h>

#define len(x) sizeof(x) / sizeof(x[0])

int x[] = {-2, -1, -1, -1, 1, 3, 6, 8, 11};
int get_index(int *p, int n)
{
	int left = 0, right = n - 1, index = -1, middle;
	while(left <= right) {
		middle = (left + right) / 2;
		if(p[middle] == middle) {
			index = middle;
			return index;
		}
		else if(p[middle] < middle)
			left = middle + 1;
		else
			right = middle - 1;
	}

	return index;
}

int main(void)
{
	printf("Result is %d\n", get_index(x, len(x)));
	return 0;
}
