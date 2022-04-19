#include <iostream>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
        {
            printf("right triangle");
        }
        else
        {
            if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > a * a + b * b)
            {
                printf("obtuse triangle");
            }
            else
                printf("acute triangle");
        }
    }
    else
        printf("it is not a triangle");
}
