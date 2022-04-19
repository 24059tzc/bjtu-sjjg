#include<stdio.h>
/*********Begin*********/
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
int Leastcommonmultiple(int m, int n)
{
    int temp,i;
    if (m < n)  
    {
        temp = m;
        m = n;
        n = temp;
    }
    for (i = m; i > 0; i++)  
        if (i % m == 0 && i % n == 0)
        {
            break;
        }

    return i;
}
 
int main(void)
{
    int x, y;
    scanf_s("%d %d", &x, &y);
    printf("最大公约数是:%d", MaxCommonFactor(x, y));
    printf("最小公倍数是:%d", Leastcommonmultiple(x, y));
    /*********End**********/
    return 0;
}
