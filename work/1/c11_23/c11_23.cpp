#include <iostream>
#include <stdio.h>

int strlen(char* s)
{
    int len = 0;
    while (*(s++)!=0)
    {
        len++;
    }
    return(len);
}
int main()
{
    int slen;
    char a[] = "abcdefg";
    char* s = a;
    slen = strlen(s);
        printf("%d",slen);
}