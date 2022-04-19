#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

#define ERROR -1
#define OK 1

typedef struct Lnode
{
	int data;
	struct Lnode* next;
}LNode, * LinkList;

/***************链表初始化**********************/
int InitList(LinkList& L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL)
	{
		printf("内存创建失败\n");
		return ERROR;
	}
	L->next = NULL;
	//根据键盘值构造链表
	LinkList r;
	r = L;
	int x;
	int i;
	for (i = 0;; i++)
	{
		scanf("%d", &x);
		if (x == -1)
			break;
		LinkList p = (LinkList)malloc(sizeof(LNode));
		if (!p)
		{
			printf("初始化失败");
			return ERROR;
		}
		p->data = x;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	return OK;
}
/******************打印单链表*****************/
void ListPrint(LinkList L)
{
	//★★★请补全代码
	LinkList p = L->next;
	if (!p)printf("链表为空\n");
	else 
	{
		while (p)
		{
			printf("%d ", p->data);
			p = p->next;
		}
		printf("\n");
	}
}
/****************求单链表的长度******************/
int ListLength(LinkList L)
{
	//★★★请补全代码
	int a=0;
	while (L->next)
	{
		a++;
		L = L->next;
	}
	return a;
}

/*********元素交换*********************/
int Exchange(LinkList& L)
{
	//★★★请补全代码
	LinkList p = L;
	for (int i = 1; i < ListLength(L)/2+ListLength(L)%2; i++)
	{
		p = p->next;
	}
	LinkList q = p->next->next;
	p->next->next = L->next->next;
	L->next->next = q;
	q = L->next;
	L->next = p->next;
	p->next = q;
	return OK;
}

/************主函数******************/
int main()
{
	int length;
	LinkList L;
	InitList(L);
	ListPrint(L);
	length = ListLength(L);
	printf("%d\n", length);
	Exchange(L);
	ListPrint(L);
	return 0;
}
