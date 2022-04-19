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
        return 0;
    }
    else if (p1 < p2)
        return 1;
    else
    {
        return -1;
    }
}
typedef struct Lnode {
    int data;
    struct Lnode* next;      //指针域
}LNode, * LinkList;
Status InitList(LinkList& L)
{
    L = (LinkList)malloc(sizeof(LNode)); //分配一个头节点
    if (L == NULL)
        return ERROR;
    L->next = NULL;
    return OK;
}
Status ListEmpty_L(LinkList L) {
    return (L == NULL);
}// ListEmpty_L
Status insert_tail(LinkList& L, int data)
{
    LinkList p = L;
    while ((p->next) != NULL)  // 目的是找到最后一个节点，最后一个节点的p指向NULL
    {
        p = p->next;
    }
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data = data;
    p->next = q;
    q->next = NULL;
    return OK;
}


Status Insite(LinkList L, int item)
{
    LinkList temp = NULL;
    LinkList target = NULL;
    if (L == NULL)
    {
        L = (LinkList)malloc(sizeof(LNode));
        if (!L)exit(0);
        (L)->data = item;
        (L)->next = NULL;
    }
    else
    {
        //输入的链表不是空的，寻找链表的尾节点，使尾节点的next=新节点。新节点的next指向头节点
        for (target = L; target->next != NULL; target = target->next);

        temp = (LinkList)malloc(sizeof(LNode));
        if (!temp) return ERROR;

        temp->data = item;
        //新节点指向头节点
        target->next = temp;
        temp->next = NULL;  //尾节点指向新节点
    }
}

int main()
{
    LinkList L,l,ll;
    InitList(L);
    int n, temp, temp2, num = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        insert_tail(L, temp);
    }
    l = L;
    for (int j = 0; j < n; j++)
    {
        ll = l->next;
        temp = ll->data;
        while (ll->next)
        {
            ll = ll->next;
            temp2 = ll->data;
            if (temp2 < temp)num++;
            else break;
        }
        l = l->next;
    }
    printf("%d\n", num);
}




