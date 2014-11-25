#include <stdio.h>

#define len(x) sizeof(x) / sizeof(x[0])

int x[] = {8,10,14,15,2,6};

int get_cyclemin(int *p, int n)
{
	int left = 0, right = n - 1, mid;
	while(left < right) {
		mid = (left + right) / 2;
		if(p[left] <= p[mid])
			left = mid + 1;
		else
			right = mid;
	}

	// for practice 2
	printf("The max # is %d\n", p[left-1]);
	return p[left];
}

int main(void)
{
	printf("The result # is: %d\n", get_cyclemin(x, len(x)));
	return 0;
}
