#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
#define OK 1
typedef int Status;
typedef int ElemType;
int compare(Status p1, Status p2)
{
    if (p1 == p2)
    {
        return 1;
    }
    else
        return 0;
}
typedef struct Lnode {
    Status data;       //数据域
    struct Lnode* next;      //指针域
}LNode, * LinkList;
Status InitList_L(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    if (!L) return ERROR;
    L->next = L;
    return OK;
}// InitList_L
Status ListEmpty_L(LinkList L) {
    return (L->next == L);
}// ListEmpty_L
int  ListLength_L(LinkList L) {
    struct Lnode* p = L->next;        //p指向第一个结点
    int i = 0;
    while (p != L) {           //遍历单链表,统计结点数
        i++;
        p = p->next;
    }
    return i;
}// ListLength_L
Status ListInsert_L(LinkList &L, int place, ElemType num) {
    LinkList temp, target;
    int i;
    if (place == 1) {  //头结点
        temp = (LinkList)malloc(sizeof(LNode));
        if (temp == NULL) {
            return ERROR;
        }
        temp->data = num;
        //获取尾结点
        temp->next = temp;
        L = temp;
    }
    else {  //其他位置
        temp = (LinkList)malloc(sizeof(LNode));
        if (temp == NULL) {
            return ERROR;
        }
        temp->data = num;
        for (i = 1, target = L; target->next != L && i != place - 1; target = target->next, i++);
        temp->next = target->next;
        target->next = temp;
    }
    return OK;
}//ListInsert_L
Status ListDelete_L(LinkList &L)
{
    ElemType e;
    LinkList q, target;
    q =L;  
    for (target = L; target->next != L; target = target->next);
    target->next = L->next;
    L = L->next;
    e = q->data; free(q);
    return e;
}//ListDelete_L
int main()
{
    LinkList L,l,ll,target; InitList_L(L);
    int n,m,i,ii=1,e;
    scanf("%d %d %d", &n, &m, &i); 
    for (int j = 1; j <=n; j++)
    {
        ListInsert_L(L, j, j);
    }
    l = L;
    for (int k = 1; k < i; k++)
    {
        l = l->next;
    }
    while (!(l->next==l))
    {
        if (ii % m == 0) {
             e = ListDelete_L(l); printf("%d ", e);
        }
        else { l = l->next; }
        ii++;
    }
    if (l->data==1||l->data==5||l->data==9)
    {
        printf("%d\n", l->data);
    }
    else printf("%d \n", l->data);
}