#include <iostream>

int main()
{
	int n,i;
	int j, k, m;
	int a[51];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int max1, max2;
	max1 = a[0];
	j = 0;
	for (i = 0; i < n; i++)
	{
		if (max1 < a[i])
		{
			max1 = a[i];
			j = i;
		}
	}
	if (j == 0)
		max2 = a[1];
	else
		max2 = a[0];
	for (k = 0; k < n&&k!=j; k++)
	{
		if (max2 < a[k])
		{
			max2 = a[k];
			m = k;
		}
	}
	printf("%d %d\n", max1, j);
	if (max1 >= 2*max2)
		printf("YES");
	else
		printf("NO");
}

