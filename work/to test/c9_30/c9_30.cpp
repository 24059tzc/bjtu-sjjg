#include "stdio.h"

int main()
{
    short int i;
    i = 1;
    i = i * 2; printf("\n i=%d", i);
    i = i * 3; printf("\n i=%d", i);
    i = i * 4; printf("\n i=%d", i);
    i = i * 5; printf("\n i=%d", i);
    i = i * 6; printf("\n i=%d", i);
    i = i * 7; printf("\n i=%d", i);
    i = i * 8; printf("\n i=%d", i);
    i = i * 9; printf("\n i=%d", i);
    i = i * 10; printf("\n i=%d", i);
    printf("\n%d", sizeof(long double));
    printf("\n");
    printf("\n");
    printf("\t");
    float a, b;
    a = 123456.789e5;
    b = a + 20;
    printf("%f\n", b);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    char c;
    c = 'A';
    printf("%c\n", c);
    printf("%d\n", c);
    printf("\n");
    printf("\n");
    float x = 4310.6429;
    {int y = 2;
    {int z = 3;
    printf("%d\n", z);
    }
    printf("%d\n", y);
    }
    printf("%x\n", x);
    printf("%-0.2f\n", x);
    float e, f, g;
    printf("请输入a，b，并用空格隔开\n");
    scanf_s("%f %f",&e,&f);
    if (e == 0)
        printf("错误，无解\n");
    else
        printf("x=-%f", e / f);
}