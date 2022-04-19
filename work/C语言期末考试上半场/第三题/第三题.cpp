#include<stdio.h>
int main()
{
	printf("please input any number from 0 to 9\n");
	int a[10] = { 1, 5, 3, 1, 2, 3, 7, 6, 3, 9 };
	int* aa = a;
	int n;
	int m=0;
	scanf("%d", &n);
	if (n >= 0 && n <= 9)
	{
		for (int i = 0; i < 10; i++)
		{
			if (*aa++==n)
			{
				m++;
			}
		}
		printf("%d appears %d times", n, m);
	}
	else
		printf("wrong input！");
}