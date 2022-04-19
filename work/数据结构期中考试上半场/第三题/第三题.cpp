#include "stdio.h" 
#include "stdlib.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE  100   //堆栈的最大容量
typedef int Status;
typedef int ElemType;

//顺序栈的结构定义
typedef struct
{
    ElemType data[MAXSIZE]; //存放堆栈元素的数组
    int top;                 //top指向栈顶元素，如果top=-1，表示空栈
}SqStack;

//初始化一个空栈
void InitStack(SqStack& S)
{
    S.top = -1;
}
//入栈操作置
Status Push(SqStack& S, ElemType e)
{
    if (S.top == MAXSIZE - 1)
    {
        return ERROR;
    }
    S.top++;
    S.data[S.top] = e;
    return OK;
}

//从栈顶弹出一个元素，赋值给e 
Status Pop(SqStack& S, ElemType& e)
{
    //★★★请补全代码
    if (S.top == -1)return ERROR;
    e = S.data[S.top];
    S.top--;
    return OK;
}

//如果是空栈，返回TRUE，否则返回FALSE
Status StackEmpty(SqStack S)
{
    //★★★请补全代码
    return S.top == -1;
}

void main()
{
    SqStack Stack;
    ElemType temp;
    InitStack(Stack);
    printf("请输入一个要入栈的元素(-1表示结束):\n");
    scanf("%d", &temp);
    while (temp != -1)
    {
        Push(Stack, temp);
        scanf("%d", &temp);
    }

    printf("对栈内元素依次进行出栈操作:\n");

    while (!StackEmpty(Stack))
    {
        if (OK == Pop(Stack,temp))
        {
            printf("%d ", temp);
        }
    }
}
