#include<stdio.h>
#define N 20

/* vertical acceleration */
const static float az[N] = { -0.0815,-0.4429,0.1076,0.0485,0.3695,0.4920,
0.8371,0.1004,0.0908,0.6239,-0.2191,0.1728,-1.1820,0.7978,0.2940,
-0.8045,-0.1717,-0.2917,0.1296,-0.1868 };

int main()
{
    int index[N]; // array store the peak index
    int type[N];  // array store the peak type 
    /* 补全代码 */
    int crests=0, valleys=0;
    int i, j, k;
    for (i = 1; i < N-1; i++)
    {
        if (az[i] > az[i + 1] && az[i] > az[i - 1])
        {
            index[i] = i;
            type[i] = 1;
            crests++;
        }
        if (az[i] < az[i + 1] && az[i] < az[i - 1])
        {
            index[i] = i;
            type[i] = -1;
            valleys++;
        }
    }
    printf("the total number of crests =%d\n", crests);
    printf("index    value\n");
    for (i = 1; i < N-1; i++)
    {
        if (type[i] == 1)
        {
            printf("%d      %.4f\n", index[i], az[i]);
        }
    }
    printf("the total number of valleys =%d\n", valleys);
    printf("index    value\n");
    for (i = 1; i < N - 1; i++)
    {
        if (type[i] == -1)
        {
            printf("%d      %.4f\n", index[i], az[i]);
        }
    }
}
