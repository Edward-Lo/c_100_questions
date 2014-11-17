#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lexical_subset(int n)
{
	int i, tmp, pos = 0, *p;
	p = (int *)malloc(n * sizeof(int));
	memset(p, 0, n * sizeof(int));
	p[0] = 1;
	printf("{}\n");
	while(1) {
		printf("{ ");
		for(i = 0; i <= pos; i++)
			printf("%d ", p[i]);
		printf("}\n");

		if(p[pos] < n) {
			tmp = p[pos];
			p[++pos] = tmp + 1;
		}
		else if(pos != 0)
			p[--pos]++;
		else
			break;
	}
	free(p);
}

void lexical_subset2(int n, int m)
{
	int i, tmp, pos = 0, *p;
	p = (int *)malloc(n * sizeof(int));
	memset(p, 0, n * sizeof(int));
	p[0] = 1;
	printf("{}\n");
	while(1) {
		printf("{ ");
		for(i = 0; i <= pos; i++)
			printf("%d ", p[i]);
		printf("}\n");

		if(p[pos] < n && pos < m - 1) {
			tmp = p[pos];
			p[++pos] = tmp + 1;
		}
		else if(pos != 0)
			p[--pos]++;
		else
			break;
	}
	free(p);
}

// for practice 3
void lexical_subset3(int n, int m)
{
	int i, tmp, pos = 0, *p;
	p = (int *)malloc(n * sizeof(int));
	memset(p, 0, n * sizeof(int));
	p[0] = 1;
	while(1) {

		while(pos != m - 1) {
			if(p[pos] < n) {
				tmp = p[pos];
				p[++pos] = tmp + 1;
			}
			else if(pos != 0)
				p[--pos]++;
			else
				break;
		}

		if(pos == m - 1) {
			printf("{ ");
			for(i = 0; i <= pos; i++)
				printf("%d ", p[i]);
			printf("}\n");
			p[--pos]++;
		}
		else if(p[pos] == n)
			break;
	}
	free(p);
}
// for practice 4
void lexical_subset4(int n)
{
	int i, tmp, pos = 0, *p;
	p = (int *)malloc(n * sizeof(int));
	memset(p, 0, n * sizeof(int));
	p[0] = n;
	while(1) {
		printf("{ ");
		for(i = 0; i <= pos; i++)
			printf("%d ", p[i]);
		printf("}\n");

		if(p[pos] > 1) {
			tmp = p[pos];
			p[++pos] = tmp - 1;
		}
		else if(pos != 0)
			p[--pos]--;
		else
			break;
	}
	printf("{}\n");
	free(p);
}

int main(void)
{
	int n, m;
	printf("Please input # to get lexical subset: ");
	scanf("%d", &n);
	lexical_subset4(n);
	// for practice 2
	//printf("Please input 2 # to get lexical subset: ");
	//scanf("%d%d", &n, &m);
	//lexical_subset3(n, m);

	return 0;
}
