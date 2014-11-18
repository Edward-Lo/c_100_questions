#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void m_subset(int n, int m)
{
	int i, tmp, pos = m - 1, *p;
	p = (int *)malloc(n * sizeof(int));
	memset(p, 0, n * sizeof(int));
	for(i = 0; i < m; i++)
		p[i] = i + 1;
	while(1) {
		printf("{ ");
		for(i = 0; i < m; i++)
			printf("%d ", p[i]);
		printf("}\n");

		if(p[0] == n - m + 1)
			break;

		if(p[m-1] == n)
			pos--;
		else
			pos = m - 1;
		p[pos]++;
		
		for(i = pos + 1; i < m; i++)
			p[i] = p[i-1] + 1;
	}
	free(p);
}

void lexical_subset(int n)
{
	int i, j, k, pos, *p;
	p = (int *)malloc(n * sizeof(int));
	memset(p, 0, n * sizeof(int));
	p[0] = 1;
	printf("{}\n");
	for(j = 0; j < n; j++) {
		pos = j;
		for(k = 0; k <= j; k++)
			p[k] = k + 1;
		while(p[0] <= n - j && p[j] <= n) {
			printf("{ ");
			for(i = 0; i <= j; i++)
				printf("%d ", p[i]);
			printf("}\n");

			if(p[j] == n)
				pos--;
			else
				pos = j;
			if(pos >= 0) {
				p[pos]++;
				for(k = pos + 1; k <= j; k++)
					p[k] = p[k - 1] + 1;
			}
			else
				break;
		}
	}
	free(p);
}

int main(void)
{
	int n, m;
	//printf("Please input 2 # to get lexical subset: ");
	//scanf("%d%d", &n, &m);
	////lexical_subset(n, m);
	printf("Please input # to get lexical subset: ");
	scanf("%d", &n);
	lexical_subset(n);

	return 0;
}
