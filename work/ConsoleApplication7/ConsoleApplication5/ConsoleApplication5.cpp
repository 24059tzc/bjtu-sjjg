#include<stdio.h>
int main()
{
    int a[10], n, i, j, min, ax;
    printf("input n = ");
    scanf("%d", &n);
    printf("input a[0]a[1]…a[% d]:\n", n - 1);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("before sort : array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])      min = j;
        ax = a[i];      a[i] = a[min];      //加一个空格
        a[min] = ax;
    }
    printf("after sort : array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
