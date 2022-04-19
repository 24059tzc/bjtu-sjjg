#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
#define OK 1
typedef char Status;
typedef char ElemType;
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
LinkList InitList_L() {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    if (!L) return NULL;
    L->next = L;
    return L;
}// InitList_L
Status ListEmpty_L(LinkList L) {
    return (L->next == L);
}// ListEmpty_L
int  ListLength_L(LinkList L) {
    struct Lnode* p = L->next;        //p指向第一个结点
    int i = 0;
    while (p!=L) {           //遍历单链表,统计结点数
        i++;
        p = p->next;
    }
    return i;
}// ListLength_L
Status GetElem_L(LinkList L, int  i) {
    ElemType e;
    struct Lnode* p = L->next;                        //初始化,p指向第一个结点  
    int j = 1;                                  // j为计数器 
    while (p!=L && (j < i)) {                 //顺指针向后查找,直到p指向第i个元素
        p = p->next;  ++j;            //或p为空
    }
    if (p==L || j > i) return ERROR;     //第i个元素不存在
    e = p->data;                       //取第i个元素
    return e;
}// GetElem_L
int LocateElem_L(LinkList L, ElemType e)
{
    struct Lnode* p = L->next;                                            //初始化,p指向第一个结点  
    int j = 1;                                                      // j为计数器 
    while (p!=L && !(compare(p->data, e)))
    {        //顺指针向后查找
        p = p->next;  ++j;                      //直到p指向第i个元素       
    }
    if (p!=L) return j;
    else return 0;
} //LocateElem_L;
ElemType PriorElem_L(LinkList L, ElemType cur_e)
{
    ElemType pre_e;
    struct Lnode* p = L;
    int j = 1;
    while (p->next!=L && !(compare(p->next->data, cur_e)))
        p = p->next; j++;
    if (p->next==L || j == 1)  return ERROR;
    pre_e = p->data;
    return pre_e;
}  // PriorElem_L
ElemType NextElem_L(LinkList L, ElemType cur_e)
{
    ElemType next_e;
    struct Lnode* p = L->next;
    while (p!=L && !(compare(p->data, cur_e)))
        p = p->next;
    if (p==L || !p->next)  return ERROR;
    next_e = p->next->data;
    return next_e;
} // NextElem_L
Status ListInsert_L(LinkList L, int place, ElemType num) {
    LinkList temp, target;
    int i;
    if (place == 1) {  //头结点
        temp = (LinkList)malloc(sizeof(LNode));
        if (temp == NULL) {
            return ERROR;
        }
        temp->data = num;
        //获取尾结点
        for (target = L; target->next != L; target = target->next);

        temp->next = L;
        target->next = temp;
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
Status Insite(LinkList L, int item)
{
    LinkList temp = NULL;
    LinkList target = NULL;
    if (L == NULL)
    {
        L = (LinkList)malloc(sizeof(LNode));
        if (!L)exit(0);
        (L)->data = item;
        (L)->next = L;
    }
    else
    {
        //输入的链表不是空的，寻找链表的尾节点，使尾节点的next=新节点。新节点的next指向头节点
        for (target = L; target->next != L; target = target->next);

        temp = (LinkList)malloc(sizeof(LNode));
        if (!temp) return ERROR;

        temp->data = item;
        temp->next = L;  //新节点指向头节点
        target->next = temp;//尾节点指向新节点
    }
}

Status ListDelete_L(LinkList L, int i)
{
    ElemType e;
    struct Lnode* p = L; int j = 0;
    while (p->next!=L && j < i - 1) {                   //寻找第i个结点,并令p指向其前驱 
        p = p->next; ++j;
    }
    struct Lnode* q;
    if (!(p->next!=L && (j <= i - 1)))return ERROR;  //删除位置不合理
    q = p->next; p->next = q->next;           //删除并释放结点
    e = q->data; free(q);
    return e;
}//ListDelete_L
Status visit(ElemType e) {
    printf("%c", (ElemType)e);
    return OK;
}
void  ListTraverse_L(LinkList L,int n)
{
    struct Lnode* L1 = L;
    for (int i = 0; i < n; i++)
    {
        L1 = L1->next;
    }
    struct Lnode* p = L1;
    do
    {
        if (p==L)
        {
            p = p->next;
            continue;
        }
        visit(p->data);
        p = p->next;
    } while ((p != L1));
    printf("\n");
}// ListTraverse_L

Status DestroyList_L(LinkList L) {
    struct Lnode* cp = L->next;
    struct Lnode* np;
    while (cp != L) {         //遍历单链表,向系统交回每一个结点
        np = cp->next;          //保存下一个结点的指针 
        free(cp);                 //删除并释放当前结点
        cp = np;                   //使下一个结点成为当前结点 
    }
    free(L);                      //删除并释放头结点
    return OK;
}// DestroyList_L
Status ClearList_L(LinkList L) {
    struct Lnode* cp = L->next;
    struct Lnode* np;
    while (cp != L) {          //遍历单链表,向系统交回每一个结点
        np = cp->next;            //保存下一个结点的指针 
        free(cp);                   //删除当前结点
        cp = np;                     //使下一个结点成为当前结点 
    }
    L->next = NULL;             //置单链表为空 
    return OK;
}
int main()
{
    struct Lnode* L = InitList_L();
    int n;
    scanf("%d", &n);
    char c = 'A';
    while (c<='Z')
    {
        Insite(L, c);
        c++;
    }
    if (n>=0)
    {
        n = n;
    }
    else
    {
        n = 27 + n;
    }
    ListTraverse_L(L,n);
}