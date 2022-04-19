//#include <stdio.h> 
//#include "stdlib.h"
//#define LIST_SIZE   1000
//#define LISTINCREMENT  10    
//#define ERROR 0
//#define OK 1
//typedef int Status;
//typedef int ElemType;
//typedef struct
//{
//	ElemType* elem;
//	int length;
//	int listsize;
//}Sqlist, * Sqlis;
//
//ElemType* Initlist()
//{
//	Sqlis L ;
//	L->elem = (ElemType*)malloc(LIST_SIZE * sizeof(ElemType));
//	if (L->elem)
//		return ERROR;
//	L->length = 0;
//	L->listsize = LIST_SIZE;
//	return L->elem;
//}
//Status DestroyList_Sq(Sqlist L) {
//	if (L->elem)   free(L->elem); // 释放分配的存储空间  
//	L->elem = NULL;
//	L->length = 0;
//	L->listsize = 0;
//	return OK;
//}//
//Status Getlist(Sqlis L)
//{
//	int i;
//	printf("\n请输入顺序表元素:");
//	for (i = 0; i < L->length; i++)
//	{
//		scanf("%d", &L->elem[i]);
//	}
//	int j = L->length;
//	L->elem[j] = '\0';
//
//	return OK;
//}
//Status Delete(Sqlis L, int m, int n)
//{
//	int i, j;
//	j = n - m + 1;
//	for (i = n + 1; i < L->length; i++)
//	{
//		L->elem[i - j] = L->elem[i];
//	}
//	L->length -= j;
//	return OK;
//}
//int main()
//{
//	int i, j;
//	Sqlist L;
//	L = {};
//	L.elem = Initlist();
//	printf("请输入元素的个数：");
//	scanf("%d", &L.length);
//	Getlist(L);
//	printf("\n输入m:");
//	scanf("%d", &i);
//	printf("\n输入n:");
//	scanf("%d", &j);
//	Delete(L, i, j);
//	for (i = 0; i < L->length; i++)
//	{
//		printf("%d ", L->elem[i]);
//	}
//	printf("\n");
//}
#include <stdio.h> 
#include "stdlib.h"
#define LIST_SIZE 1000
#define LISTINCREMENT 10    
#define ERROR 0
#define OK 1
typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType* elem;
	int length;
	int listsize;
}Sqlist,*Sqlis;
Sqlist L;
Sqlis Initlist()
{
	
	L.elem = (ElemType*)malloc(LIST_SIZE * sizeof(ElemType));
	L.length = 0;
	L.listsize = LIST_SIZE;
	return &L;
}
Status DestroyList_Sq(Sqlis L) {
	if (L->elem)   free(L->elem); // 释放分配的存储空间  
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
	return OK;
}//
Status Getlist(Sqlis L)
{
	int i;
	printf("\n请输入顺序表元素:");
	for (i = 0; i < L->length; i++)
	{
		scanf("%d", &L->elem[i]);
	}

	return OK;
}
Status Delete(Sqlis L, int m, int n)
{
	int i, j;
	j = n - m + 1;
	for (i = n + 1; i < L->length; i++)
	{
		L->elem[i - j] = L->elem[i];
	}
	L->length -= j;
	return OK;
}
int main()
{
	int i, j;
	Sqlis LL=Initlist();
	printf("请输入元素的个数：");
	int a;
	scanf("%d", &a);
	LL->length = a;
	Getlist(LL);
	printf("\n输入m:");
	scanf("%d", &i);
	printf("\n输入n:");
	scanf("%d", &j);
	Delete(LL, i, j);
	for (i = 0; i < LL->length; i++)
	{
		printf("%d ", LL->elem[i]);
	}
	printf("\n");
}