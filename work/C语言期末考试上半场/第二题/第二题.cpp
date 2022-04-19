#include<stdio.h>
int main()
{
	int m,i;
	long long int c=0;
	scanf("%d", &m);
	if (m < 1)
		printf("Wrong input！");
	else
	{
		for (i = 1; c <= m; i++)
		{
			c = c + i * i;
		}
		printf("The maximum integer satisfing the inequality is %d", i - 2);
	}
}