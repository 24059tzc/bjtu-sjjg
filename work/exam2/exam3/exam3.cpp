#include<stdio.h>
#include<math.h>
#define N 20   
#define K 0.8

/* vertical acceleration */
const static float az[N] = { -0.0815,-0.4429,0.1076,0.0485,0.3695,0.4920,
0.8371,0.1004,0.0908,0.6239,-0.2191,0.1728,-1.1820,0.7978,0.2940,
-0.8045,-0.1717,-0.2917,0.1296,-0.1868 };

int main()
{
    /* 补全代码 */
    int i;
    float az1[N];
    float Sk;
    float Amax, Amin;
    for (i = 0; i < N; i++)
    {
        az1[i] = fabsf(az[i]);
    }
    Amax = az1[0];
    Amin = az1[0];
    for (i = 0; i < N; i++)
    {
        if (az1[i] > Amax)
            Amax = az1[i];
        if (az1[i] < Amin)
            Amin = az1[i];
    }
    printf("max=%.4f,min=%.4f\n", Amax, Amin);
    Sk = K * powf((Amax - Amin), 0.25);
    printf("the step size is %.4f meters", Sk);
}
