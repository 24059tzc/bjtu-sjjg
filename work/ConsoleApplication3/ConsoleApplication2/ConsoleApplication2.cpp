#include <stdio.h>
#include <string.h>
int main(void)
{
    /*********Begin*********/
    char a[100], b[100];
    gets_s(a);
    gets_s(b);
    char c, d;
    int i, j=0, k=0;
    c = b[0];
    d = a[0];
    int e = strlen(a);
    for (i = 0; i < strlen(b); i++)
    {
        if (b[i] <= c)
            c = b[i];
    }
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] >= d)
        {
            d = a[i];
            j = i;
            k = i;
        }
    }
    for (j=e; j > k; j--)
    {
        a[j ] = a[j-1];
    }
    a[k] = c;
    for (i = 0; i <= e; i++)
        printf("%c", a[i]);
    /*********End**********/
    return 0;
}