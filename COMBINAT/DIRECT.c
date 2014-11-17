#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_direct(int n)
{
	int i;
	char *p = (char *)malloc((n+1) * sizeof(char));
	memset(p, '0', n * sizeof(char));
	printf("{}\n");
	while(1) {
		for(i = 0; i < n; i++)
			if(p[i] == '1')
				p[i] = '0';
			else {
				p[i] = '1';
				break;
			}
		if(i == n)
			break;

		printf("{ ");
		for(i = 0; i < n; i++)
			if(p[i] == '1')
				printf("%d ", i + 1);
				// for practice 2
				//printf("%c ", 'A' + i);
		printf("}\n");
	}
	free(p);
}

// for practice 1
void get_direct2(int n)
{
	int i;
	unsigned long p = 0UL, q, k;
	printf("{}\n");
	while(1) {
		for(i = 0; i < n; i++)
			if(p & 1UL << i)
				continue;
			else {
				// modify p here
				q = 1UL << i;
				k = ~(q-1);
				p = (p & k) | q;
				break;
			}
		if(i == n)
			break;

		printf("{ ");
		for(i = 0; i < n; i++)
			if(p & 1UL << i)
				printf("%d ", i + 1);
		printf("}\n");
	}
}

int main(void)
{
	int n;
	printf("Please input a #: ");
	scanf("%d", &n);
	get_direct2(n);
	return 0;
}
