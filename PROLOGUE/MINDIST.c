#include <stdio.h>
#include <limits.h>

#define min(x, y) ((x) < (y)) ? (x) : (y)
#define len(x) sizeof(x) / sizeof(x[0])

int f[] = {1,3,7,13,15};
int g[] = {9,11,18,21};

int min_distance(int *x, int *y, int m, int n)
{
	int minimum = INT_MAX, last_min = minimum;
	int index_x = 0, index_y = 0;
	int min_x = 0, min_y = 0;

	while(index_x < m && index_y < n) {
		last_min = minimum;
		if(x[index_x] > y[index_y]) {
			minimum = min(minimum, x[index_x] - y[index_y]); 
			if(last_min != minimum)
				min_x = index_x, min_y = index_y;
			index_y++; 
		}
		else {
			minimum = min(minimum, y[index_y] - x[index_x]); 
			if(last_min != minimum)
				min_x = index_x, min_y = index_y;
			index_x++;
		}
	}

	// for practice 3
	printf("Min dist of array is %d from x[%d] = %d and y[%d] = %d\n", minimum, min_x, x[min_x], min_y, y[min_y]);

	return minimum;
}

int main(void)
{
	printf("The min dist of f[] and g[] is %d\n", min_distance(f, g, len(f), len(g)));
	return 0;
}
