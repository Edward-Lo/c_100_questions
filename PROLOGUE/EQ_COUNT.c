#include <stdio.h>
#define len(x) sizeof(x) / sizeof(x[0])
int f[] = {1,3,4,7,9};
int g[] = {3,5,7,8,10};
int coincidence_count(int *f, int *g, int m, int n)
{
	int index_f, index_g;
	int i;
	int count;
	int prev_f, prev_g;
	int after_f, after_g;
	
	count = index_f = index_g = 0;
	while(index_f < m && index_g < n) {
		if(f[index_f] < g[index_g])
			index_f++;
		else if(f[index_f] > g[index_g])
			index_g++;
		else {
			// for practice 1
			printf("f[%d] = g[%d] = %d\n", index_f, index_g, f[index_f]);
			// for practice 2
			prev_f = index_f;
			prev_g = index_g;
			while(f[prev_f] == g[prev_g]) {
				printf("f[%d] = g[%d] = %d\n", prev_f, prev_g, f[prev_f]);
				prev_g++;
			}

			count++, index_f++, index_g++;
		}
	}

	return count;
}

int main(void)
{
	printf("The count of f = g is %d\n", coincidence_count(f, g, len(f), len(g)));
	return 0;
}
