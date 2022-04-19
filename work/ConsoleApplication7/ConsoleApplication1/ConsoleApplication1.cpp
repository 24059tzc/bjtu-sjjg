//本关任务：有三个候选人，每个选民只能投一票，写一程序，用结构体存储数据，求出得票结果。
//三个候选人为”Li“， “Zhang“，”Sun“。
//测试输入：
//10
//Li
//Li
//Sun
//Zhang
//Zhang
//Sun
//Li
//Sun
//Zhang
//Li
//预期输出：
//Li : 4
//Zhang : 2
//Sun : 3
//测试输入数据说明：
//输入数据第一行包含一个整数n，表示有n个人投票。接下来的每一行包含某个候选人的名字。
#include<stdio.h>
#include<string.h>
int main()
{
	struct candidate
	{
		int Li;
		int Zhang;
		int Sun;
	}b;
	b.Li = 0;
	b.Sun = 0;
	b.Zhang = 0;
	int n,i;
	char a[6];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", a);
		if (strcmp(a, "Li") == 0)
		{
			b.Li++;
		}
		else if (strcmp(a, "Zhang") == 0)
		{
			b.Zhang++;
		}
		else if (strcmp(a, "Sun") == 0)
		{
			b.Sun++;
		}
	}
	printf("Li : %d\nZhang : %d\nSun : %d", b.Li,b.Zhang,b.Sun);
}