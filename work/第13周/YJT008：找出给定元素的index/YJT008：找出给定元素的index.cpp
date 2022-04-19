#include <stdio.h>
int main()
{
	char c;
	for (int i = 0; i < 6; i++)
	{
		c=getchar();
	}
	int temp[15];
	int j = 0;
	int num = 1;
	int temp2;
	while (c!=']')
	{
		c = getchar();
		temp2 = 0;
		while (c>='0'&&c<='9')
		{
			temp2 = num * (c - '0') + temp2;
			c = getchar();
		}
		num = 1;
		temp[j++] = temp2;
	}
	for (int i = 0; i < 8; i++)
	{
		getchar();
	}
	int target;
	scanf("%d", &target);
	int begin = -1, end = -1;
	for (int i = 0; i < j; i++)
	{
		if (temp[i] == target) {
			begin = i; break;
		}
	}
	for (int i = j-1; i >= 0; i--)
	{
		if (temp[i] == target) {
			end = i; break;
		}
	}
	printf("[%d,%d]\n", begin,end);
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
