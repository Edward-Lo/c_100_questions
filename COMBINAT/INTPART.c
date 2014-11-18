#include <stdio.h>
#include <stdlib.h>

void show_result(int *p, int *q, int part_no)
{
	int i, j;
	for(i = 1; i <= part_no; i++)
		for(j = 0; j < q[i] ; j++)
			printf("%d ", p[i]);
	printf("\n");
}

void get_part(int n)
{
	int i, part_no, sum, size;
	int *p, *q;
	p = (int *)malloc(n * sizeof(int));
	q = (int *)malloc(n * sizeof(int));
	// init
	p[1] = n, q[1] = part_no = 1;

	while(1) {
		show_result(p, q, part_no);
		if(p[1] == 1)
			break;
		sum = p[part_no] == 1 ? q[part_no--] + 1 : 1;
		size = p[part_no] - 1;
		if(q[part_no] != 1)
			q[part_no++]--;
		p[part_no] = size;
		q[part_no] = sum / size + 1;
		if(sum % size)
			p[++part_no] = sum % size, q[part_no] = 1;
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
