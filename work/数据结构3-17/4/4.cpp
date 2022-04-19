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
    float a;//数据域
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
Status insert_tail(LinkList& L, int data, float a)
{
    LinkList p = L;
    while ((p->next) != NULL)  // 目的是找到最后一个节点，最后一个节点的p指向NULL
    {
        p = p->next;
    }
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data = data;
    q->a = a;
    p->next = q;
    q->next = NULL;
    return OK;
}
Status visit(LinkList L) {
    printf("%g^%d", L->a, L->data);
    return OK;
}
void  ListTraverse_L(LinkList L)
{
    struct Lnode* p = L->next;
    while (p)
    {
        visit(p);
        if (p->next)
        {
            printf(" ");
        }
        p = p->next;
    }
    printf("\n");
}// ListTraverse_L
Status ListDelete_L(LinkList& L, int i) {
    LinkList p = L; int j = 0;
    while (p->next && j < i - 1) {                   //寻找第i个结点,并令p指向其前驱 
        p = p->next; ++j;
    }
    if (!(p->next && j < i - 1))return ERROR;  //删除位置不合理
    LinkList q = p->next; p->next = q->next;           //删除并释放结点
    free(q);
    return OK;
}//ListDelete_L
Status Insite(LinkList L, int item, float a)
{
    LinkList temp = NULL;
    LinkList target = NULL;
    if (L == NULL)
    {
        L = (LinkList)malloc(sizeof(LNode));
        if (!L)exit(0);
        (L)->data = item;
        L->a = a;
        (L)->next = NULL;
    }
    else
    {
        //输入的链表不是空的，寻找链表的尾节点，使尾节点的next=新节点。新节点的next指向头节点
        for (target = L; target->next != NULL; target = target->next);

        temp = (LinkList)malloc(sizeof(LNode));
        if (!temp) return ERROR;

        temp->data = item;
        temp->a = a;
        //新节点指向头节点
        target->next = temp;
        temp->next = NULL;  //尾节点指向新节点
    }
}
void AddPolyn(LinkList& Pa, LinkList& Pb, LinkList& L) {
    LinkList qa = Pa->next, qb = Pb->next;
    LinkList ha = L;//qa和qb分别指向Pa和Pb的头结点
    while (!ListEmpty_L(qa) && !ListEmpty_L(qb)) {    //Pa和Pb均非空
        int a = qa->data, b = qb->data;  //a和b为两表中当前比较元素
        float sum;
        switch (compare(a, b)) {
        case -1:                                     //多项式Pa中当前结点的指数值较小
            ha->next = qa;
            qa = qa->next;
            ha = ha->next; break;
        case 0:                                             //两者的指数值相等
            sum = qa->a + qb->a;
            if (sum != 0.0) {
                if (!ha->next)
                {
                    ha->next = (LinkList)malloc(sizeof(LNode));
                }
                ha->next->data = qa->data;
                ha->next->a = sum;
                ha = ha->next;
            }
            else {                                            //删除多项式Pa中当前结点
                ListDelete_L(qa, 1);
            }
            qb = qb->next;
            qa = qa->next; break;
        case 1:                                           //多项式Pb中当前结点的指数值较小
            ha->next = qb;
            ha = ha->next;
            qb = qb->next; break;
        } //switch
    }//while
    if (!ListEmpty_L(qb)) ha->next = qb;
    else
    {
        ha->next = qa;
    }
}//AddPolyn


int main()
{
    LinkList L, LL;
    InitList(L);
    float a;
    int data;
    int i = 0;
    scanf("%f^%d", &a, &data);
    while (!(a == 0.0 && data == 0))
    {
        insert_tail(L, data, a);
        scanf("%f^%d", &a, &data);
        i++;
    }
    i = 0;
    InitList(LL);
    scanf("%f^%d", &a, &data);
    while (!(a == 0.0 && data == 0))
    {
        insert_tail(LL, data, a);
        scanf("%f^%d", &a, &data);
        i++;
    }
    LinkList ll;
    InitList(ll);
    AddPolyn(L, LL, ll);
    ListTraverse_L(ll);
}