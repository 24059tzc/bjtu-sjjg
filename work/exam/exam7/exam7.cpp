#include <iostream>

int main()
{
    char a[81];
    int i = 0,k;
    scanf("%s", a);
    printf("The string is: ");
    puts(a);
    while (a[i]!='\0')
    {
        i++;
    }
    printf("Len=%d\n", i);
    for (k = 0; k <= i; k++)
    {
        if (k == i)
        {
            printf("Yes");
            break;
        }
        if (a[k] != a[i - k - 1])
        {
            printf("No");
            break;
        }
        
    }
}

