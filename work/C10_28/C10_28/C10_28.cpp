#include<stdio.h>
int main(void)
{
    /*********Begin*********/
    int i, j, k;
    int m, n;
        scanf("%d %d", &m, &n);
    int a[10][11];
    int max[11];
    int b[11][11] ;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    for (i = 0; i < m; i++)
    {
        max[i] = a[i][0];
        for (k = 0; k < j; k++)
        {
            if (max[i] <= a[i][k])
            {
                max[i] = a[i][k];
                b[i][k] = 1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        max[i] = a[i][0];
        for (k = 0; k < j; k++)
        {
            if (max[i] <= a[i][k])
            {
                max[i] = a[i][k];
                b[i][k] = 1;
            }
        }
    }
        /*********End**********/
        return 0;
}