
#include<stdio.h>
int MaxCommonFactor(int a, int b)
{
	int c;
	if (a <= 0 || b <= 0)
		return -1;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main(void)
{
	/*********Begin*********/
	int a, b, c;
	scanf_s("%d,%d", &a, &b);
	c = MaxCommonFactor(a, b);
	printf("%d", c);
	/*********End**********/
	return 0;
}
//#include<stdio.h>
//#define PI 3.14
//int main(void)
//{
	//int a =c= 3, b = 5, t;
	//t = a;
	//a = b;
	//b = t;
	//printf("%d,%d", a, b);
	/*********Begin*********/
	//double  h, C1, Sb, r, Vb;
	//scanf_s("%lf,%lf", &r, &h);
	//Sb = 4 * PI * r * r;
	//C1 = 2 * PI * r;
	//Vb = PI * r * r * h;
	//printf("C1=%.2f\n", C1);
	//printf("Sb=%.2f\n", Sb);
	//printf("Vb=%.2f\n", Vb);
	/*********End**********/
	//return 0;
//}

//#include<stdio.h>
//#define prince 30
//int main(void)
//{
	/*********Begin*********/
	//int x;
	//scanf("%d", &x);
	//printf("%d", x* prince);
	/*********End**********/
	//return 0;
	//int a;
	//printf("%d", 'a');
	//int a, b, c,d;
	//scanf_s("%d %d %d %d", &a, &b,&c,&d);
	//printf("%d\n", a * (b * b + 4 * a * c));
	//printf("%d", (a + b) / (c * d));

		/*********Begin*********/
		// a;
		//scanf_s("%d", &a);
		//printf("%d %d %d", a / 100, a / 10 - (a / 100) * 10, a - (a / 100) * 100 - (a / 10 - (a / 100) * 10) * 10);

		/*********End**********/
		//return 0;
	//float c, d;
	//c = 3 / 5;
	//d = 3.0 / 5;
	//printf("%f,%f", c, d);
 /*********Begin*********/
    //int a, b, c, d, e;
	//scanf_s("%d %d %d %d %d", &a, &b, &c, &d, &e);
	//printf("%d %f", (a + b + c + d + e), (a + b + c + d + e) / 5.0);
	/*********End**********/
	//return 0;
	//int a = 3;
	//float b = 3.0;
	//printf("%d,%f", b, a);
//}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
