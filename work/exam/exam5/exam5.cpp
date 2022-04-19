#include <iostream>

int main()
{
    int a[16];
    int i,n,j;
    for (i = 0; i < 15; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < 15; i++)
        printf("%d ", a[i]);
    printf("\n");
    scanf("%d", &n);
    for (i = 0; i < 16; i++)
    {
        if (i < 15)
        {
            if (n == a[i])
            {
                printf("the index of %d is %d\n", n, i);
                break;
            }
        }
        else
            printf("No same height in the array\n");
    }
    for (i = 0; i < 16; i++)
    {
       for (j = i + 1; j < 15; j++)
       {
           if (i < 15)
           {
               if (a[i] == a[j])
               {
                   printf("the same height is %d,  and the indices are: %d, %d\n", a[i], i , j);
                   break;
               }
           }
           else
               printf("No same height in the array");
       }
    }
}
