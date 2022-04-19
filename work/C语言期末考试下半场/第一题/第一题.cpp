#include<stdio.h>
#define N 10

int main()
{
    int rssi[N] = { -35, -50, -81, -82, -55, -90, -83, -85, -70, -75 };
    /* 请补全代码 */
    int n=0;
    for (int i = 0; (i < N)&&(n<=3); i++)
    {
        if (rssi[i] < -80)
        {
            n++;
        }
        else { n = 0; }
        if (n == 3)
        {
            printf("At point %d，the mobile changed to celluar network.", i);
        }
    }
}
