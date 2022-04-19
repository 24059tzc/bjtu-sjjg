#include<stdio.h>
#define N 10

void sort(int a[], int n)
{
    /* 请补全代码 */
    int* s = a;
    int max;
    int k;
    for (int i = 0; i < n; i++)
    {
        max = *(s+i);
        k = i;
        for (int j = i; j < n; j++)
        {
            if (max < *(s+j))
            {
                max = *(s+j);
                k = j;
            }
        }
        *(s + k) = *(s + i);
        *(s + i) = max;
    }
}

int main()
{
    int rssi[N] = { -35, -50, -81, -82, -55, -90, -83, -85, -70, -75 };
    int i;
    sort(rssi, N);
    printf("{%d", rssi[0]);
    for (i = 1; i < N; i++)
        printf(",%d", rssi[i]);
    printf("}\n");
}
