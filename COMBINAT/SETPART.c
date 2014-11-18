#include <stdio.h>
#include <stdlib.h>

void show_result(int *p, int n)
{
	int i, j, count = 0;
	for(i = 1; i <= n; i++) {
		printf("{ ");
		for(j = 0; j < n; j++)
			if(p[j] == i) {
				printf("%d ", j + 1);
				count++;
			}
		printf("} ");

		if(count == n) {
			printf("\n");
			break;
		}
	}
}

void get_part(int n)
{
	int *p, *q;
	int i, j;
	p = (int *)malloc(n * sizeof(int));
	q = (int *)malloc(n * sizeof(int));

	for(i = 0; i < n; i++)
		p[i] = 1, q[i] = 2;
	
	while(1) {
		show_result(p, n);
		for(i = n - 1; i > 0 && p[i] == q[i]; i--);	
		if(!i)
			break;
		p[i]++;
		for(j = i + 1; j < n; j++)
			p[j] = 1, q[j] = q[i] + (p[i] == q[i] ? 1 : 0);
	}

	free(p);
	free(q);
}

int main(void)
{
	int n;
	printf("Please input a #: ");
	scanf("%d", &n);
	get_part(n);
	return 0;
}
