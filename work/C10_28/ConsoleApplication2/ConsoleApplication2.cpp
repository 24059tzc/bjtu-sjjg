#include<stdio.h>
#include<string.h>
int main(void)
{
    /*********Begin*********/
    char a[100], b[100], c[100];
    char t[100];
    gets_s(a);
    gets_s(b);
    gets_s(c);
    if (strcmp(a,b)==1)
    {
        strcpy(t, a);
        strcpy(a, b);
        strcpy(b, t);
    }
    if (strcmp(a, c) == 1)
    {
        strcpy(t, a);
        strcpy(a, c);
        strcpy(c, t);
    }
    if (strcmp(b, c) == 1)
    {
        strcpy(t, b);
        strcpy(b, c);
        strcpy(c, t);
    }
    puts(a);
    puts(b);
    puts(c);



    /*********End**********/
    return 0;
}