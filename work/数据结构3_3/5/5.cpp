#include <stdio.h>

int main()
{
    int a[20];
    int n;
    int b[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int max ;
    int k=0,m=0;
    int aa=0;
    for (int j = 0; j < n; j++)
    {
        max = a[0];
        for (int i = 0; i < n; i++)
        {
            if (max < a[i])
            {
                max = a[i];
                k = i;
            }
        }
        if (m % 2 == 0)
        {
            b[aa] = max;
        }
        else
        {
            b[n - aa - 1] = max;
            aa ++;
        }
        a[k] = 0;
        m++;
    }
    for (int j = 0; j < n; j++)
    {
        if (j != n - 1)
            printf("%d ", b[j]);
        else
            printf("%d\n", b[j]);
    }
}
