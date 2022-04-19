#include <stdio.h>

int main()
{
    int count[11] = { 1,4,6,9,11,25,31,46,83,100 };
    int i, j, k;
    scanf_s("%d", &j);
    if (j >= 1 && j <= 100)
    {
        for (i = 0; i <= 8; i++)
        {
            if (j >= count[i] && j < count[i + 1])
            {
                for (k = 10; k > i + 1; k--)
                {
                    count[k] = count[k - 1];
                }
                count[i + 1] = j;
                break;
            }
        }
    }
    else if (j < 1)
    {
        for (k = 10; k > 0; k--)
            count[k] = count[k - 1];
        count[0] = j;
    }
    else
        count[10] = j;
    for (i = 0; i < 11; i++)
        printf("%d ", count[i]);
}