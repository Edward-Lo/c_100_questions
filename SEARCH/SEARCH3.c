#include <stdio.h>

#define len(x) sizeof(x) / sizeof(x[0])

int x[] = {1,2,3,4,5,26};
int y[] = {26};
int z[] = {11,15,17,26,39};

void find_eq(int *x, int *y, int *z, int len_x, int len_y, int len_z)
{
	int px = 0, py = 0, pz = 0;
	int found = 0;

	while(px < len_x && py < len_y && pz < len_z) {
		if(x[px] < y[py])
			px++;
		else if(y[py] < z[px])
			py++;
		else if(z[pz] < x[px])
			pz++;
		else {
			found = 1;
			break;
		}
	}

	if(found)
		printf("We found common = %d\n", x[px]);
	else
		printf("Sorry, not found\n");
}

int main(void)
{
	find_eq(x, y, z, len(x), len(y), len(z));
	return 0;
}
