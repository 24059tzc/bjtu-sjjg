#include<stdio.h>
#include<string.h>
#include<iostream>
int main(void)
{
    /*********Begin*********/
    char a[20];
    int i,n;
    gets_s(a);
    n=strlen(a);
    for (i = n-1;i >= 0; i--)
        printf("%c", a[i]);


    /*********End**********/
    return 0;
}