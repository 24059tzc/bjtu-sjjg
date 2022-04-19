#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
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
Status InitStack(SqStack& S) {
    S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
    if (!S.base) exit(ERROR);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;

}
Status ClearStack(SqStack& S) {
	S.top = S.base;
	return OK;
}// ClearStack

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
Status Pop(SqStack& S, SElemType& e) {
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
typedef int QElemType;
typedef int Status;
typedef struct Qnode {
	QElemType   data;
	struct Qnode* next;
}QNode, * QueuePtr;

typedef struct {
	QueuePtr  front;  //队头指针   
	QueuePtr  rear;   //队尾指针
}LinkQueue;
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) return ERROR;
	Q.front->next = NULL;
	return OK;
}//InitQueue
Status QueueEmpty(LinkQueue Q) {
	return (Q.front == Q.rear);
}// QueueEmpty
int  QueueLength(LinkQueue Q) {
	QueuePtr p = Q.front->next;   //p指向队头
	int i = 1;
	while (p != Q.rear) {  //遍历链队列,统计结点数
		i++;
		p = p->next;
	}
	return i;
}// QueueLength
Status GetHead(LinkQueue Q, QElemType& e) {
	if (Q.front == Q.rear) return ERROR;
	e = Q.front->next->data;
	return OK;
}//GetHead
Status EnQueue(LinkQueue& Q, QElemType e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) return ERROR;
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}//EnQueue
Status DeQueue(LinkQueue& Q, QElemType& e) {
	if (Q.front == Q.rear) return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}//DeQueue
Status DestroyQueue(LinkQueue& Q) {
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}// DestroyQueue
Status ClearQueue(LinkQueue& Q) {
	Q.rear = Q.front; QueuePtr p = Q.front->next;
	Q.front->next = NULL;
	QueuePtr q;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}// ClearQueue
Status visit(QElemType e) {
	printf("%d ", (int)e);
	return OK;
}
Status QueueTraverse(LinkQueue Q) {
	for (QueuePtr p = Q.front->next; p != NULL; p = p->next)
		visit(p->data);
	printf("\n");
	return OK;
}// QueueTraverse
int main()
{
    int c,b,N,n,a,aa,cc;
    SqStack s;
	LinkQueue Q;
	InitQueue(Q);
	SElemType e=0;
    InitStack(s);
    scanf("%d %d", &b,&c);
	if (b<=2)
	{
		b = 2;
	}
    for (int j = b; j <= c; j++)
    {
        e = 0;
        for (int i = 2; i <= sqrt(j); i++)
        {
            if (j % i == 0)
            {
                e = 1;
                break;
            }
        }
        if (e==1)
        {
			continue;
        }
        N = j;
        while (N!=0)
        {
            n = N % 10;
            Push(s, n);
			EnQueue(Q, n);
			N = N / 10;
        }
		while (1)
		{
			if (!DeQueue(Q, aa)) {
				printf("%d\n", j); break;
			}
			Pop(s, a);
			if (a!=aa)
			{
				break;
			}
		
		}
		ClearQueue(Q);
		ClearStack(s);
    }
    
}
