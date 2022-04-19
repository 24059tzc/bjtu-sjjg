#include<stdio.h>
//编写函数
/*********Begin*********/
long  long int aaa(int n)
{
    int i;
    long  long int m = 1;
    for (i = 1; i <= n; i++)
    {
        m = m * i;
    }
    return m;
}
long long  int nsa(int n)
{
    long long  int c = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        c = c + aaa(i);
    }
    return c;
}
/*********End**********/
int main(void)
{
    /*********Begin*********/
    long  long int sum;
    int n;
    scanf_s("%d", &n);
    sum = nsa(n);
    printf("%lld", sum);
    /*********End**********/
    return 0;
}
