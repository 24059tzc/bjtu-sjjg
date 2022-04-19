// 3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

int main()
{
    int h[15];
	for (int i = 0; i < 15; i++)
	{
		scanf("%d", &h[i]);
	}
	int f;
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", h[i]);
	}
	printf("\n");
	scanf("%d", &f);
	for (int i = 0; i < 15; i++)
	{
		if (f == h[i])
		{
			printf("the index of %d is %d\n", f, i);
			break;
		}
		if (i == 14)
			printf("there is no such height\n");
	}
	int n = 0;
	for (int j = 0; j < 15; j++)
	{
		for (int i = j+1; i < 15; i++)
		{
			if (h[j] == h[i])
			{
				printf("the same height is %d,and the indices are:%d,%d\n", h[j], j, i);
				n++;
			}
			}
	}
	if (n == 0)
		printf("No same height in the array\n");

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
