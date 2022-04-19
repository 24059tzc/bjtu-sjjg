#include <stdio.h>
#define number 20
int main()
{
	struct letter
	{
		char c;
		int num = 0;
	}let[20][number];
	int n,u=0,m;
	char c;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		u = 0;
		for (int j = 0; j < 100; j++)
		{
			c = getchar();
			if (c == '\n')break;
			else
			{
				for (int k = 0; k <= number; k++)
				{
					if (k == number)
					{
						let[i][u].c = c;
						let[i][u].num = 1;
						u++;
						break;
					}
					if (let[i][k].c == c) {
						let[i][k].num++;
						break;
					}
				}
			}
		}
	}
	letter temp[number];
	for (int i = 0; i < n; i++)
	{
		u = 0;
		int max = let[i][0].num;
		for (int j = 0; j < number; j++)
		{
			if (let[i][j].num > max) max = let[i][j].num;
		}
		for (int j = 0; j < number; j++)
		{
			if (let[i][j].num==max)
			{
				temp[u] = let[i][j];
				u++;
			}
		}
		int order = 0;
		for (int j = 0; j <= u; j++)
			{
				if (j == u)
				{
					order = 1;
				}
				if (temp[j].num!=0)
				{
					max = temp[j].c;
					m = j;
					break;
				}
			}//找未被输出的ascll码最小值
			if (order==1)
			{
				break;
			}
			for (int j = 0; j < u; j++)
			{
				if (max>temp[j].c&&temp[j].num!=0)
				{
					max = temp[j].c;
					m = j;
				}
			}
			printf("%c %d", temp[m].c, temp[m].num);
			temp[m].num = 0;
		    printf("\n");
	}
}
