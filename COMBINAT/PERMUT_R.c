#include <stdio.h>
#include <stdlib.h>

void rotate(int *p, int n)
{
	int i, tmp = p[n];
	for(i = n; i > 0; i--)
		p[i] = p[i-1];
	p[0] = tmp;
}

void show_perm(int n)
{
	int i, j, pos = n - 1;
	int *p = (int *)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		p[i] = i + 1;
	while(pos) {
		printf("{ ");
		for(j = 0; j < n; j++)
			printf("%d ", p[j]);
		printf("}\n");

		pos = n - 1;
		rotate(p, pos);
		while(p[pos] == pos + 1 && pos != 0)
			rotate(p, --pos);
	}
	free(p);
}

int main(void)
{
	int n;
	printf("Please input a #: ");
	scanf("%d", &n);
	show_perm(n);
	return 0;
}
