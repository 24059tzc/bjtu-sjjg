#include"stdio.h"
int main(void)
{
   // int x,p;
    //scanf_s("%d", &x);

//    if (((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0))
 //       p = 1;
 //   else
  //      p = 1;
  //  if (p == 1)
  //      printf("Y/n");
  //  else
   //     printf("N/n");
    //return 0;
        /*********Begin*********/
        int a, x;
        double b, y;
        scanf_s("%d,%lf", &a, &b);
        x = (int)b;
        if ((b - x) == 0)
            y = b;
        else y = b + 1;
        if (a == 0)
        {
            int prince = 10;
            if (y <= 1)
                printf("Price: %.2f\n", prince);
            else
                printf("Price: %.2f\n", prince + 3 * (y - 1));
        }
        else if (a == 1)
        {
            float prince = 10;
            if (y <= 1)
                printf("Price: %.2f\n", prince);
            else
                printf("Price: %.2f\n", prince + 4 * (y - 1));
        }
        else if (a == 2)
        {
            float prince = 15;
            if (y <= 1)
                printf("Price: %.2f\n", prince);
            else
                printf("Price: %.2f\n", prince + 5 * (y - 1));
        }
        else if (a == 3)
        {
            float prince = 15;
            if (y <= 1)
                printf("Price: %.2f\n", prince);
            else
                printf("Price: %.2f\n", prince + 6.5 * (y - 1));
        }
        else if (a == 4)
        {
            float prince = 15;
            if (y <= 1)
                printf("Price: %.2f\n", prince);
            else
                printf("Price: %.2f\n", prince + 10 * (y - 1));
        }
        else
            printf("Error in Area\nPrice：0.00");

        /*********End**********/
        return 0;
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
