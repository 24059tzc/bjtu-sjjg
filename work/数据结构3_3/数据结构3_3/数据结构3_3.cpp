#include <iostream>
int main()
{
	int n;
	float a[10][10];
	float aa = 0, bb = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%f", &a[i][j]);
	}
	for (int k = 0; k < n; k++)
	{
		for (int m = 0; m < n; m++)
		{
			if ((k == m)||(k+m+1==n))
			{
				aa = aa + a[k][m];
				bb++;
			}
		}
	}
	if (n % 2 != 0)
	{
		aa = aa + a[n / 2][n / 2];
		bb++;
	}
	printf("The matrix is:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if(j==n-1)
				printf("%.2f", a[i][j]);
			else
			printf("%.2f ", a[i][j]);
		printf("\n");
	}
	printf("The mean value is: %.2f\n", aa / bb);
	return 0;
}