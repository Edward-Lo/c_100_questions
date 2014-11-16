#include <stdio.h>
#define len(x) sizeof(x) / sizeof(x[0])

int x[]  = {3,0,6,2,0,0,1,4,5,2};

int head_tail(int *x, int n)
{
	int prefix = x[0], suffix = x[n - 1];
	int prefix_x = 0, suffix_x = n - 1;
	int count = 0;

	while(prefix_x <= n - 1 && suffix_x >= 0) {
		if(prefix < suffix)
			prefix += x[++prefix_x];
		else if(suffix < prefix)
			suffix += x[--suffix_x];
		else {
			// for practice 2
			printf("Prefix of x[0...%d] = suffix of x [%d...%d] = %d\n", prefix_x, n - 1, suffix_x, prefix);
			count++, prefix += x[++prefix_x], suffix += x[--suffix_x];
		}
	}

	return count;
}

int main(void)
{
	printf("There are %d of same sum for prefix and suffix\n", head_tail(x, len(x)));
	return 0;
}
