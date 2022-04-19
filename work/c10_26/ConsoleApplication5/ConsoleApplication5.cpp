#include <stdio.h>

int main()
{
    int number[11];
    int i, j, k;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &number[i]);
    }
    int max = number[0];
    for (i = 0; i < 10; i++)
    {
        if (max <= number[i])
        {
            max = number[i];
            j = i;
        }
    }
    for (; j < 9; j++)
    {
        number[j] = number[j + 1];
    }

    for (i = 0; i < 9; i++)
    {
        printf("%d ", number[i]);
    }
}