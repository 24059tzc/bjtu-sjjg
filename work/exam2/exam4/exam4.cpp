#include<stdio.h>
#define N 8

int main()
{
    /* position {x,y} */
    int pos[N][2] = { {10,8},{11,7},{5,5},{9,2},{14,1},{7,3},{10,4},{7,6} };
    /* 补全代码 */
    int i, j, k;
    int a[3];
    int max;
    for (i = 0; i < N; i++)
    {
        max = pos[i][1];
        k = i;
        for (j = i; j < N; j++)
        {
            if (max > pos[j][1])
            {
                max = pos[j][1];
                k = j;
            }
        }
        a[0] = pos[i][0];
        a[1] = pos[i][1];
        pos[i][0] = pos[k][0];
        pos[i][1] = pos[k][1];
        pos[k][0] =a[0];
        pos[k][1] = a[1];
    }
    for (i = 0; i < N; i++)
    {
        printf("(%d,%d)\n", pos[i][0], pos[i][1]);
    }
}
