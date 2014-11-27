#include <stdio.h>

#define len(x) sizeof(x) / sizeof(x[0])

int x[][5] = { {1,3,7,8,13},
			  {2,4,8,10,14},
			  {5,6,9,12,15},
			  {7,12,13,15,19},
			  {11,13,16,18,25}
			};

void find_k(int *x, int k, int n)
{
	int i = 0, j = n - 1;
	int found = 0;

	while(i < n && j >= 0) {
		//printf("scan for i = %d j = %d\n", i, j);
		//printf("x[i][j] = %d\n", x[i*n+j]);
		if(x[i*n+j] > k)
			j--;
		else if(x[i*n+j] < k)
			i++;
		else {
			printf("found @ x = %d y = %d\n", i, j);
			found = 1;
			break;
		}
	}

	if(!found)
		printf("Sorry, can't find %d\n", k);
}

int main(void)
{
	int n;
	printf("Please input a # you want to find: ");
	scanf("%d", &n);
	//printf("sizeof x[0] = %d\n", sizeof(len(x[0])));
	find_k((int *)x, n, 5);
	return 0;
}
