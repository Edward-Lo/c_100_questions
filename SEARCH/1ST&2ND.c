#include <stdio.h>
#include <limits.h>

#define len(x) sizeof(x) / sizeof(x[0])

int x[] = {7,9,5,11,3,1};

void get_mins(int *x, int left, int right, int *s1, int *s2)
{
	int p1, p2, p3, p4;
	int mid;

	if(left > right)
		*s1 = *s2 = INT_MAX;
	else if(left == right)
		*s1 = x[left], *s2 = INT_MAX;
	else {
		mid = (left + right) / 2;
		get_mins(x, left, mid, &p1, &p2);
		get_mins(x, mid + 1, right, &p3, &p4);
		
		// find 1st & 2nd
		if(p1 < p3)
			*s1 = p1, *s2 = (p2 < p3) ? p2 : p3;
		else
			*s1 = p3, *s2 = (p1 < p4) ? p1 : p4;
	}
}

int main(void)
{
	int s1, s2, s3;
	get_mins(x, 0, len(x) - 1, &s1, &s2);
	printf("Found 1st & 2nd small #: %d %d\n", s1, s2);
	//get_mins2(x, 0, len(x) - 1, &s1, &s2, &s3);
	//printf("Found 1st & 2nd & 3rd small #: %d %d %d\n", s1, s2, s3);
	return 0;
}
