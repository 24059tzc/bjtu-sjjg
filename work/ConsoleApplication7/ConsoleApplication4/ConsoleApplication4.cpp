#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);


    int a[1000];
    int i, temp;
    int count = 0;
    temp = n;
    for (i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    i = 0;
    while (n > 1)
    {
        if (a[i] != 0)   
        {
            count++;
        }
        if (count == 3)
        {
            a[i] = 0; 
            count = 0;
            n--;  
        }
        i++;
        if (i == temp)
        {
            i = 0;
        }
    }
    for (i = 0; i < temp; i++)
    {
        if (a[i] != 0)  
        {
            printf("%d", a[i]);
        }


    }


    return 0;
}