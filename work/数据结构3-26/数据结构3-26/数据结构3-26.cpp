#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
#define STACKINCREMENT 100

typedef int SElemType;
typedef int Status;

typedef struct {
    SElemType* base;
    SElemType* top;
    int stacksize;
}SqStack;//顺序栈

//初始化顺序栈
Status InitStack(SqStack &S) {
    S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
    if (!S.base) exit(ERROR);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;

}

//判断栈是否为空
Status StackEmpty(SqStack S) {
    return (S.top == S.base);
}

//入栈
Status Push(SqStack& S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {      //栈满,追加存储空间
        S.base = (SElemType*)realloc(S.base, (S.stacksize +
            STACKINCREMENT) * sizeof(SElemType));
        if (!S.base) return ERROR;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

//出栈
Status Pop(SqStack &S,SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

int main()
{
    int N;
    SqStack s;
    SElemType e;
    InitStack(s);
    scanf("%d", &N);//输入十进制数
    while (N) {
        e = N % 2;
        Push(s, e);
        N = N / 2;
    }
    while (s.top != s.base) {
        Pop(s, e);
        printf("%d", e);//输出二进制数
    }
    printf("\n");
    return 0;
}
