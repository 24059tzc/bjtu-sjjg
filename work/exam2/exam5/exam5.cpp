#include<stdio.h>
#define N 8

int main()
{
	/* position {x,y} */
	int pos[N][2] = { {14,1},{9,2},{7,3},{10,4},{5,5},{7,6},{11,7},{10,8} };
	/* 补全代码 */
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < pos[i][0]-1; k++)
			printf("-");
		printf("*\n");
	}
}
