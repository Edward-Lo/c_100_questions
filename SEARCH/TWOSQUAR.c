#include <stdio.h>
#include <math.h>

void get_squaresum(int n)
{
	int sqrt_r = floor(sqrt((double) n) + 0.5);
	int row = 1, col = sqrt_r, sum = 0;

	while(row <= col && col >= 1) {
		sum = row * row + col * col;
		if(sum == n) {
			printf("%d2 + %d2 = %d\n", row, col, n);
			row++, col--;
		}
		else if(sum < n)
			row++;
		else
			col--;
		sum = 0;
	}
}

int main(void)
{
	int n;
	printf("Please input a #: ");
	scanf("%d", &n);
	get_squaresum(n);
	return 0;
}
