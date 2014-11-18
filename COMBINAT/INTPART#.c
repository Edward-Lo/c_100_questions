#include <stdio.h>

unsigned long get_part(int n, int m)
{
	if(n == 1 || m == 1)
		return 1;
	else if(n > m)
		return get_part(n, m-1) + get_part(n-m, m);
	else if(n == m)
		return 1 + get_part(n, m-1);
	else if(n < m) {
		printf("Is this possible?\n");
		return get_part(n, n);
	}
}

int main(void)
{
	int n, m;
	printf("Please input 2 # to compute: ");
	scanf("%d%d", &n, &m);
	printf("The # of partition is %d\n", get_part(n, m)); 
	return 0;
}
