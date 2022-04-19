// c10_7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//#include<math.h>
#include <iostream>

//int main()
//{
//    double r, n, m,d;
//    scanf_s("%lf %lf %lf", &r, &n, &m);
//    d = pow((1 + r), n);
//    printf("%.2f", m*d);
//    printf("%d", sizeof(unsigned int));
//}
#include<stdio.h>
int main(void)
{
  /*********Begin*********///    int a, b, c, t, d, e;printf("请输入三个整数:");scanf("%d %d %d", &a, &b, &c);if (a > b)  {   a = t, a = b, b = t;}
   // if (b > c) { d = b, b = c, c = d; }if (a > c) { a = e, a = c, c = e; }
   // printf("从小到大排列为:%d,%d,%d", a, b, c);
    /*********End**********/

//    int x = 1;
//    double y = 3.0;
 
//    printf("%d", sizeof(x + y));
//    return 0;
 //   int x = 5, y = 4;
 //   printf("%d", x <<2);
 //   double a, b, c;
 //   scanf("%lf", &a);   
 //   printf("%d\n", (int) a);
 //   c = a - (int)a;
 //   printf("%f\n",c);
    char a;
    scanf("%c", &a);
    a = ((a >= 'A' && a <= 'Z') ? (a + 32): a);
    printf("%c", a);
}
// abcdefghijklmnopqrstuvwxyz运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
