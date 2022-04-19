#include <iostream>

int main()
{
    int n,i,j,k;
    float a[11][11];
    float b=0;
    scanf("%d", &n);
    if (n > 10)
    {
        printf("Wrong input, the dimension should not be greater than 10. ");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%f", &a[i][j]);
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j || i + j == n - 1)
                {
                    b = b + a[i][j];
                }
            }
        }
        printf("The matrix is:\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (j == 0)
                    printf("%.1f ", a[i][j]);
                else if (j == n - 1)
                    printf("%.0f", a[i][j]);
                else
                    printf("%.0f ", a[i][j]);
            }
            printf("\n");
        }
        if(n%2!=0)
        printf("The mean value is: %.2f", b / (2 * n - 1));
        else
            printf("The mean value is: %.2f", b / (2 * n));
    }
}
