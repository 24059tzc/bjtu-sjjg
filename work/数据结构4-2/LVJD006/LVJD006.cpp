#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
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
void YangHuiTriangle(LinkQueue &Q,int N)
{
	EnQueue(Q, 1);   //第1行元素入队
	int temp, x;
	for (int n = 2; n <= N; n++) {    //产生第i行元素并入队，同时打印第i-1行元素
		EnQueue(Q, 1);
		for (int i = 1; i <= n - 2; i++) {//利用第n-1行元素产生第n行的中间n-2个元素
			DeQueue(Q, temp);   printf("%4d", temp);
			GetHead(Q, x);
			temp = temp + x;
			EnQueue(Q, temp);
		}
		DeQueue(Q, x);  printf("%4d\n", x);   //打印第N-1行的最后一个元素
		EnQueue(Q, 1);                             //第N行的最后一个元素入队
	}
	while (!QueueEmpty(Q)) {        //打印最后一行元素
		DeQueue(Q, x);   printf("%4d", x);
	}
	printf("\n");
}
int main()
{
	LinkQueue Q;
	InitQueue(Q);
	int n;
	scanf("%d", &n);
	YangHuiTriangle(Q, n);
}



