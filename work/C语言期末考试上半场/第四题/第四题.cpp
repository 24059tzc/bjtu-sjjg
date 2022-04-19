#include<stdio.h>
int main()
{
	int m, n,add;
	scanf("%d%d", &m, &n);
	int a[5][5];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	FILE* fp;
	fp = fopen("matrix.txt", "w+");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fprintf(fp, "%d ", a[i][j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	for (int i = 0; i < m; i++)
	{
		add = 0;
		for (int j = 0; j < n; j++)
		{
			add = add + a[i][j];
		}
		printf("sum of row %d is %d\n",i,add);
	}
}