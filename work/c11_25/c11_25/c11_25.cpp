#include <stdio.h>

int main()
{
    int* p;
    printf("%d\n",sizeof(p));
    char* a;
    printf("%d\n", sizeof(a));
    printf("%d\n", &a);
}