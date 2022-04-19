#include <iostream>
#define p 1300000000;
float pe;
int fun(float x);
int main()
{
	float rat = 0.02;
	int m;
	while (rat >= 0.001)
	{
		m = fun(rat);
		printf("rat is %.3f,It needs %d years and the population is%.0f\n", rat, m, pe);
		rat -= 0.005;
		printf("陶子辰sb");
	}
}
int fun(float x)
{
	int n = 0;
	pe = p;
	while (pe < 1500000000)
	{
		pe = pe * (1 + x);
		n++;
	}
	return n;
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
