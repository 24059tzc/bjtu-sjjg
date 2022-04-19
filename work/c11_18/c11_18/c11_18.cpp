#include<stdio.h>

int setbits(int x, int p, int n, int y)
{
    return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}


int main()
{
    int x;
    int y ;
    int p ;
    int n ;
    int r;
    scanf("%d %d %d %d", &x, &y, &p, &n);
    r = setbits(x, p, n, y);
    printf("%d", r); //r的结果应为121
    return 0;
    本关任务（习题6.3）：定义宏setbits(x, p, n, y)，将整数x从第p位开始的向右n位（p从右至左编号为0~15）
        置为y的最右边n位的值，其余位保持不变。
}
