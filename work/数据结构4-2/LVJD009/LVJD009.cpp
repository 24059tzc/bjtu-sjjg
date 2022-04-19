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

int main()
{
	LinkQueue Q1,Q2;
	InitQueue(Q1);
	int n,num,a[30],i=0;
	InitQueue(Q2);
	scanf("%d", &num);
	for(int k=0;k<num;k++)
	{
		scanf("%d", &n);
		 if (n%2==0)EnQueue(Q2, n);
		 else EnQueue(Q1, n);
	}
	while (1)
	{
		if (!DeQueue(Q1, n)) {
			while (DeQueue(Q2, n)) {
				a[i] = n; i++;
			}
			break;
		}
		a[i] = n; i++;
		if (!DeQueue(Q1, n)) {
			while (DeQueue(Q2, n)) {
				a[i] = n; i++;
			}break;
		}
		a[i] = n; i++;
		if (!DeQueue(Q2, n)) {
			while (DeQueue(Q1, n)) {
				a[i] = n; i++;
			}break;
		}
		a[i] = n; i++;
	}
	for (int j = 0; j < num-1; j++)
	{
		printf("%d ", a[j]);
	}
	printf("%d\n", a[num - 1]);
}