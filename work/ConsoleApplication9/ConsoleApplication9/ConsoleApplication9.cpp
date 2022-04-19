// ConsoleApplication9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
int a[6][11];
void b()
{
	int bb;
	for (int j = 0; j < 5; j++)
	{
		bb = 0;
		for (int i = 0; i < 10; i++)
		{
			bb = a[j][i] + bb;
		}
		float ff = bb / 5;
		printf("第%d名同学平均成绩%.1f\n", j+1, ff);
	}
}
void c()
{
	int cc;
	for (int i = 0; i < 10; i++)
	{
		cc = 0;
		for (int j = 0; j < 5; j++)
		{
			cc = a[j][i]+cc;
		}
		float ccc=cc/10;
		printf("第%d科平均成绩为%.1f\n", i+1, ccc);
	}
}
int main()
{
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scanf("%d", &a[i][j]);
		}
		
	}
	b();
	c();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
