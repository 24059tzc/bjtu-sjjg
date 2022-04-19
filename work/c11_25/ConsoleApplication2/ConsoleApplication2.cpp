#include <stdio.h>
#include"stdlib.h"
int main()
{
    char* s;
    int a;
    s = (char*)malloc(5 * sizeof(char));
    gets_s(s, 5);
    scanf_s("%d", &a);
    puts(s);
}