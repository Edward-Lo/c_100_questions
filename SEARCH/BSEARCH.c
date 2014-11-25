#include<stdio.h>

int x[] = {1,2,3,7,9,10,24};

#define len(x) sizeof(x) / sizeof(x[0])

int bisearch(int *x, int len, int n)
{
	int left = 0, right = len - 1, mid;
	int index = -1;

	while(left <= right) {
		mid = (left + right) / 2;
		if(x[mid] < n)
			left = mid + 1;
		else if(x[mid] > n)
			right = mid - 1;
		else {
			index = mid; 
			break;
		}
	}

	return index;
}

int main(void)
{
	int i, n;
	printf("Please input a # you wanna search: ");
	scanf("%d", &n);			
	i = bisearch(x, len(x), n);
	if(i >= 0)
		printf("Yes we found it @ x[%d]\n", i);
	else
		printf("Sorry, can't found it\n");
	return 0;
}
