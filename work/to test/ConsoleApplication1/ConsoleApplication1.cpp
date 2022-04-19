#include<stdio.h>

    int MaxCommonFactor(int a, int b)
{
    int c;
    if (a <= 0 || b <= 0)
        return -1;
    while (b != 0)
    {
        c = a % b;
        printf("%d\n", c);
        a = b;
        printf("%d\n", a);
        b = c;
        printf("%d\n", b);
    }
    return a;
}
    int main(void)
    {
    printf("%d",MaxCommonFactor(86, 64));
}
