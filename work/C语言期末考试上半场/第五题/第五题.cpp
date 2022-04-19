#include<stdio.h>
int main()
{
	int h[13];
	int l[13];
	int diff[13];
	for (int i = 0; i < 12; i++)
	{
		scanf("%d", &h[i]);
	}
	for (int i = 0; i < 12; i++)
	{
		scanf("%d", &l[i]);
	}
	for (int i = 0; i < 12; i++)
	{
		diff[i] = h[i] - l[i];
	}
	printf("high\tlow\tdiff\n");
	for (int i = 0; i < 12; i++)
	{
		printf("%d\t%d\t%d\n", h[i], l[i], diff[i]);
	}
	int max = diff[0];
	int min = diff[0];
	int maxnum=0,minnum=0;
	for (int i = 0; i < 12; i++)
	{
		if (max < diff[i])
		{
			max = diff[i];
			maxnum = i;
		}
		if (min > diff[i])
		{
			min = diff[i];
			minnum = i;
		}
	}
	printf("Max.diff.: %d, Month : %d\nMin.diff. : %d, Month : %d\n", max, maxnum + 1, min, minnum + 1);
}