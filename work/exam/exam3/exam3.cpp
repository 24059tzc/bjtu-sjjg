#include <iostream>

int main()
{
    int N;
    scanf("%d", &N);
    int i,j=0, a = 0,b=1;
    float prince;
    for (i = 1; b<= N; i++)
    {
        b = 2 * b;
        if (b > N)
            break;
        a = a + b;
        j = j + 1;

    }
    prince = a * 0.8;
    printf("the average cost for each day is %.2f yuan", prince/j);
}
