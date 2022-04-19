#include <stdio.h>
int amin(int a[5][4])
{
    // 请在此添加你的代码
    /********** Begin *********/
    int i, j, k, min[5];
    for (i = 0; i < 5; i++)
    {
        min[i] = a[i][0];
        for (k = 0; k < 4; k++)
        {
            if (min[i] >= a[i][k])
            {
                min[i] = a[i][k];
            }
        }
    }
    int b;
    int min2 = min[0];
    for (b = 0; b < 5; b++)
    {
        if (min2 >= min[b])
        {
            min2 = min[b];
        }
    }
    return min2;


    /**********  End  **********/
}

int main()
{
    int a[5][4], i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);
    printf("min=%d\n", amin(a));
    return 0;
}
