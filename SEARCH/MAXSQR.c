#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define min(a,b,c) (((a) < (b)) ? ((a) < (c) ? (a) : (c)) \
							    : ((b) < (c) ? (b) : (c)))

int x[][8] = { {1,1,1,0,0,0,0,0},
			  {0,1,1,1,1,0,0,0},
			  {0,0,1,1,1,1,1,0},
			  {0,0,0,1,1,1,1,1},
			  {0,1,1,1,1,1,1,1},
			  {0,1,1,1,1,0,1,1},
			  {0,0,1,1,1,0,0,0},
			  {0,0,1,1,1,1,0,0} };

int get_maxsqr(int p[][8], int *x, int *y, int n, int k)
{
	int **tmp;
	int i, j, result;
	tmp = (int **)malloc(n * sizeof(int *));

	for(i = 0; i < n; i++)
		tmp[i] = (int *)malloc(n * sizeof(int));

	for(j = 0; j < n ; j++) 
		tmp[n-1][j] = p[n-1][j] == k ? 1 : 0;

	for(i = n-2; i >= 0; i--) {
		tmp[i][n-1] = p[i][n-1] == k ? 1 : 0;
		for(j = n-2; j >= 0; j--) {
			if(p[i][j] == k) {
				tmp[i][j] = min(tmp[i][j+1], tmp[i+1][j+1], tmp[i+1][j]) + 1;
				//printf("i = %d, j = %d, min = %d\n", i, j, min(tmp[i][j+1], tmp[i+1][j+1], tmp[i+1][j]));
				//printf("tmp[%d][%d] = %d ", i, j+1, tmp[i][j+1]);
				//printf("tmp[%d][%d] = %d ", i+1, j+1, tmp[i+1][j+1]);
				//printf("tmp[%d][%d] = %d ", i+1, j, tmp[i+1][j]);
				//printf("tmp[%d][%d] = %d\n", i, j, tmp[i][j]);
				
				if(tmp[i][j] > result) {
					result = tmp[i][j];
					*x = i, *y = j;
				}
			}
			else
				tmp[i][j] = 0;
		}
	}

	for(i = 0; i < n; i++)
		free(tmp[i]);

	free(tmp);
	
	return result;
}

// for practice 3
int get_maxsqr2(int p[][8], int *x, int *y, int n, int k)
{
	int **tmp;
	int i, j, result;
	tmp = (int **)malloc(2 * sizeof(int *));

	for(i = 0; i < 2; i++)
		tmp[i] = (int *)malloc(n * sizeof(int));

	for(j = 0; j < n ; j++) 
		tmp[1][j] = p[n-1][j] == k ? 1 : 0;

	for(i = n-2; i >= 0; i--) {
		tmp[0][n-1] = p[i][n-1] == k ? 1 : 0;
		for(j = n-2; j >= 0; j--) {
			if(p[i][j] == k) {
				tmp[0][j] = min(tmp[0][j+1], tmp[1][j+1], tmp[1][j]) + 1;
				
				if(tmp[0][j] > result) {
					result = tmp[0][j];
					*x = i, *y = j;
				}
			}
			else
				tmp[0][j] = 0;
		}
		memcpy(tmp[1], tmp[0], n * sizeof(int));
	}

	for(i = 0; i < 2; i++)
		free(tmp[i]);

	free(tmp);
	
	return result;
}

int main(void)
{
	int i, j, n;
	//n = get_maxsqr(x, &i, &j, 8, 1);
	n = get_maxsqr2(x, &i, &j, 8, 1);
	printf("Get max square = %d @ x = %d y = %d\n", n, i, j);
	return 0;
}
