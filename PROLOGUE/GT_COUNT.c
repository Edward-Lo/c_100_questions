#include <stdio.h>
#define len(x) sizeof(x) / sizeof(x[0])
int f[] = {1,3,5,7,9};
int g[] = {2,3,4,7,8};
int dominance_count(int *f, int *g, int m, int n)
{
	int index_f, index_g;
	int i;
	int count;
	
	count = index_f = index_g = 0;
	while(index_f < m && index_g < n) {
		if(f[index_f] <= g[index_g])
			index_f++;
		else {
			index_g++, count += m - index_f;
			// for practice 3
			printf("Subarray { ");
			for(i = 0; i < index_g; i++)
				printf("%d ", g[i]);
			printf("} < f[%d] = %d\n", index_f, f[index_f]);
		}
	}

	return count;
}

int main(void)
{
	printf("The count of f > g is %d\n", dominance_count(f, g, len(f), len(g)));
	return 0;
}
