#include<stdio.h>
#define N 20//说明：
#define THRE 0.25 // 判定阈值

/* vertical acceleration peaks */
const static float peak[N] = {-0.0815, -0.4429, 0.1076, 0.0485, 0.3695, 0.4920,
0.8371, 0.1004, 0.0908, 0.6239, -0.2191, 0.1728, -1.1820, 0.7978, 0.2940,
-0.8045, -0.1717, -0.2917, 0.1296, -0.1868};


int main()
{
    float realpeak[N];
    /*   补全代码   *///因为出题定义问题增加数组前后两值，并更改N值
    int index[N]; 
    float realpeak2[N];
    int index2[N];
    int rindex2[N];
    int type[N]; 
    int a=0;
    int type2[N];
    int crests = 0, valleys = 0;
    int i, j, k=0;
    for (i = 1; i < N - 1; i++)
    {
        if (peak[i] > peak[i + 1] && peak[i] > peak[i - 1])
        {
            index[i] = i;
            type[i] = 1;
            crests++;
        }
        if (peak[i] < peak[i + 1] && peak[i] < peak[i - 1])
        {
            index[i] = i;
            type[i] = -1;
            valleys++;
        }
    }
        for (i = 1; i<N-1;i++)
        {
            if ((type[i] == 1 || type[i] == -1)&&(peak[i] > THRE || peak[i] < -THRE))
            {
                realpeak[k] = peak[i];
                k++;
                rindex2[k] = i;
            }
        }
    
    printf("the number of real peaks = %d\nthe real peak values:\n", k);
    for (i = 0; i < k; i++)
    {
        printf("%.4f ", realpeak[i]);
    }
    for (i = 1; i < k - 1; i++)
    {
        if (realpeak[i] > realpeak[i + 1] && realpeak[i] > realpeak[i - 1])
        {
            index2[i] = i;
            type2[i] = 1;
        }
        if ((realpeak[i] < realpeak[i + 1]) && (realpeak[i] < realpeak[i - 1]))
        {
            index2[i] = i;
            type2[i] = -1;
        }
    }
    for (i = 1; i < k ; i++)
    {
        if (index2[i] == index[rindex2[i]])
            a++;
    }
    printf("\nthe number of step is %d", a);
}

