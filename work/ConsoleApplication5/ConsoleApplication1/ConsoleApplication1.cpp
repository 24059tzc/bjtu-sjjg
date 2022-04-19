#include<stdio.h>
//编写题目要求的函数
/*********Begin*********/
double sun(int n)
{
    double s = 1, m = 1;
    float i;
    for (i = 1; i <= n; i++)
    {
        m = (i / (2*i + 1)) * m;
        s = s + m;
    }
    return s;
}
/*********End**********/
int main(void)
{
    /*********Begin*********/
    int n;
    double sum;
    scanf_s("%d", &n);
    sum = sun(n);
    printf("%.10f", sum);
    /*********End**********/
    return 0;
}
