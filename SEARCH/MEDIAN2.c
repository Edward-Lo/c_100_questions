#include <stdio.h>
#include <stdlib.h>

#define len(x) sizeof(x) / sizeof(x[0])

int x[] = {1,3,5,7,9};
int y[] = {2,4,6,8,10};

int cmp(const void *x, const void *y)
{
	int *a = (int *)x;
	int *b = (int *)y;
	return *a - *b;
}

int get_median(int *x, int *y, int n)
{
	int left_x = 0, right_x = n - 1, mid_x;
	int left_y = 0, right_y = n - 1, mid_y;
	int i, number = 0, count = 0;
	int *p, result;

	while((right_x - left_x > 1) && (right_y - left_y > 1)) {
		mid_x = (left_x + right_x) / 2;
		mid_y = (left_y + right_y) / 2;

		if(x[mid_x] < y[mid_y]) {
			count += (mid_x - left_x);
			left_x = mid_x, right_y = mid_y;
		}
		else {
			count += (mid_y - left_y);
			left_y = mid_y, right_x = mid_x;
		}
	}

	//printf("left_x = %d, right_x = %d, left_y = %d, right_y = %d\n", left_x, right_x, left_y, right_y);
	//printf("count = %d\n", count);
	p = (int *)malloc( (right_x - left_x + right_y - left_y) * sizeof(int));
	for(i = left_x; i <= right_x; i++)
		p[number++] = x[i];
	for(i = left_y; i <= right_y; i++)
		p[number++] = y[i];

	//for(i = 0; i < number; i++)
		//printf("p[%d] = %d\n", i, p[i]);

	qsort(p, number, sizeof(int), cmp);
	result = p[n - count - 1];
	free(p);
	return result;
}

int main(void)
{
	printf("The result is %d\n", get_median(x, y, len(x)));
	return 0;
}
