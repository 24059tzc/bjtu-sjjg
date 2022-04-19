#include<stdio.h>
#include<string.h>
int main(void)
{
    /*********Begin*********/
    int a, i, j, b = 0, c;
    scanf("%d", &a);
    char ch[10][50];
    for (i = 0; i < a + 1; i++)
        gets_s(ch[i]);
    for (i = 1; i < a + 1; i++)
    {
        for (j = 0; j < strlen(ch[i]); j++)
        {
            if (ch[i][j] >= '0' && ch[i][j] <= '9')
            {
                b++;
            }
        }
        printf("%d\n", b);
        b = 0;
    }

    /*********End**********/
    return 0;
}