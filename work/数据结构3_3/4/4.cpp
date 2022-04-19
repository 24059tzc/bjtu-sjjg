#include <stdio.h>

int main()
{
	int n, a[20];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int max = a[0];
	int k=0;
	for (int i = 1; i < n; i++)
	{
		if (max<a[i])
		{
			max = a[i];
			k = i;
		}
	}
	int max2 = a[0];
	if (k == 0)
	{
		max2 = a[1];
	}
	for (int i = 1; i < n; i++)
	{
		if (i != k)
		{
			if (max2 < a[i])
			{
				max2 = a[i];
			}
		}
	}
	printf("%d %d ", max, k);
	if (max >= (2 * max2))
	{
		printf("YES\n");
	}
	else
		printf("NO\n");
}
