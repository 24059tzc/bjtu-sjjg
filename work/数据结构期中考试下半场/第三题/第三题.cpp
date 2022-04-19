#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW 0
#define OK 1
#define ERROR 0
#define MAXQSIZE  10   //最大队列长度
#define MAXCHAR 255
#define MAXINT 255

typedef int Status;
typedef unsigned int QElemType;
typedef struct {
    QElemType* base;   //初始化的动态分配存储空间
    int  front;                    //头指针   
    int  rear;                     //尾指针
} SqQueue;

//构造一个空队列Q
Status InitQueue(SqQueue& Q) {
    Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base) return ERROR;
    Q.front = Q.rear = 0;
    return OK;
}//InitQueue

Status DestroyQueue(SqQueue& Q) {
    if (Q.base) free(Q.base);
    Q.base = NULL;
    Q.front = Q.rear = 0;
    return OK;
}// DestroyQueue


Status EnQueue(SqQueue& Q, QElemType e)
{
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR; //队列满
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;

}//EnQueue

Status DeQueue(SqQueue& Q, QElemType& e)
{
    if (Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}//DeQueue

//打印队列
Status QueuePrint(SqQueue Q) {

    //★★★请补全代码
    QElemType e;
    while (Q.front != Q.rear)
    {
        DeQueue(Q, e);
        printf("%d ", e);
    }
    return OK;
}

int main()
{
    SqQueue Q;
    int i, j;
    int n = 5; /* m序列阶数 */
    unsigned int C[] = { 1,0,0,1,0,1 }; /* m序列移位寄存器系数 */
    unsigned int a_init[] = { 1,0,0,0,0 }; /* m序列移位寄存器初始值 */
    unsigned int m[MAXINT];  /*  存储m序列 */
    unsigned int an;    /* m序列输出临时变量 */
    InitQueue(Q);
    for (i = 0; i < n; i++) {
        if (!EnQueue(Q, a_init[i])) exit(OVERFLOW);
    }

    printf("the initial value of queue elements:\n");
    QueuePrint(Q);
    printf("\n");

    //★★★请补全代码   //产生m序列
    QElemType temp;
    for (i = 0; i < 31; i++)
    {
        an = 0;
        for (int k = 1; k <=n; k++)
        {
            an = (a_init[n - k] * C[k]+an)%2;
        }
        for (int k = 0; k < n-1; k++)
        {
            a_init[k] = a_init[k + 1];
        }
        a_init[n-1] = an;
        EnQueue(Q, an);
        DeQueue(Q, temp);
        m[i] = temp;
    }
    printf("the m sequence is:\n");
    DestroyQueue(Q);
    for (i = 0; i < 31; i++)
        printf("%d", m[i]);
    printf("\n");
}
