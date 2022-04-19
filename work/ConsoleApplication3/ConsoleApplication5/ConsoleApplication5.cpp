#include<stdio.h>
#include<string.h>
#include<cstring>
int main(void)
{
    /*********Begin*********/
    char a[100], b[100], c[100], d[100];
    char e[] = { '\0' };
    int n, i;
    gets_s(a);
    gets_s(b);
    scanf("%d", &n);
    strncpy(c, a, n);
    strcat(c,e);
    for (i = n; i < strlen(a); i++)
    {
        d[i - n] = a[i];
    }
    strcat(c,b);
    strcat(c,e);
    strcat(c,d);
    strcat(c,e);
    for (i = 0; i < strlen(c); i++)
    {
        printf("%c", c[i]);
    }
    /*********End**********/
    return 0;
}