#include <stdio.h>
int main()
{   
    int i, j, k, max[11];
    int m, n;
    int a[10][10];
    printf("Input m, n:");
    scanf("%d,%d", &m, &n);
    printf("Input %d*%d array: ", m, n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int num[10];
    for (i = 0; i < m; i++)
    {
        max[i] = a[i][0];
        for (k = 0; k < n; k++)
        {
            if (max[i] <= a[i][k])
            {
                max[i] = a[i][k];
                num[i] = k;
            }
        }
    }
    int b;
    int max2 = max[0];
    int num2;
    for (b = 0; b < 5; b++)
    {
        if (max2 <= max[b])
        {
            max2 = max[b];
            num2 = b;
        }
    }
    printf("max=%d, row=%d, col=%d", max2, num2+1, num[num2]+1);
    return 0;
}