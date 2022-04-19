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
    int data;       //数据域
    struct Lnode* next;      //指针域
}LNode, * LinkList;
LinkList InitList_L() {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    if (!L) return NULL;
    L->next = NULL;
    return L;
}// InitList_L
Status ListEmpty_L(LinkList L) {
    return (L->next == NULL);
}// ListEmpty_L
int  ListLength_L(LinkList L) {
    struct Lnode* p = L->next;        //p指向第一个结点
    int i = 0;
    while (p) {           //遍历单链表,统计结点数
        i++;
        p = p->next;
    }
    return i;
}// ListLength_L
Status GetElem_L(LinkList L, int  i) {
    ElemType e;
    struct Lnode* p = L->next;                        //初始化,p指向第一个结点  
    int j = 1;                                  // j为计数器 
    while (p && (j < i)) {                 //顺指针向后查找,直到p指向第i个元素
        p = p->next;  ++j;            //或p为空
    }
    if (!p || j > i) return ERROR;     //第i个元素不存在
    e = p->data;                       //取第i个元素
    return e;
}// GetElem_L
int LocateElem_L(LinkList L, ElemType e)
{
    struct Lnode* p = L->next;                                            //初始化,p指向第一个结点  
    int j = 1;                                                      // j为计数器 
    while (p && !(compare(p->data, e)))
    {        //顺指针向后查找
        p = p->next;  ++j;                      //直到p指向第i个元素       
    }
    if (p) return j;
    else return 0;
} //LocateElem_L;
ElemType PriorElem_L(LinkList L, ElemType cur_e)
{
    ElemType pre_e;
    struct Lnode* p = L;
    int j = 1;
    while (p->next && !(compare(p->next->data, cur_e)))
        p = p->next; j++;
    if (!p->next || j == 1)  return ERROR;
    pre_e = p->data;
    return pre_e;
}  // PriorElem_L
ElemType NextElem_L(LinkList L, ElemType cur_e)
{
    ElemType next_e;
    struct Lnode* p = L->next;
    while (p && !(compare(p->data, cur_e)))
        p = p->next;
    if (!p || !p->next)  return ERROR;
    next_e = p->next->data;
    return next_e;
} // NextElem_L
Status ListInsert_L(LinkList L, int i, ElemType e) {
    struct Lnode* p = L;  int j = 0;
    while (p && j < i - 1) { p = p->next; ++j; }      //寻找第i-1个结点
    if (!p || j > i - 1) return -1;                   //i小于1或大于表长
    struct Lnode* s = (LinkList)malloc(sizeof(LNode));        //生成新结点
    s->data = e;
    s->next = p->next;                               //插入L中
    p->next = s;
    return OK;
}//ListInsert_L
Status ListDelete_L(LinkList L, int i)
{
    ElemType e;
    struct Lnode* p = L; int j = 0;
    while (p->next && j < i - 1) {                   //寻找第i个结点,并令p指向其前驱 
        p = p->next; ++j;
    }
    struct Lnode* q;
    if (!(p->next && (j <= i - 1)))return ERROR;  //删除位置不合理
    q = p->next; p->next = q->next;           //删除并释放结点
    e = q->data; free(q);
    return e;
}//ListDelete_L
Status visit(ElemType e) {
    printf("%d", (int)e);
    return OK;
}
void  ListTraverse_L(LinkList L)
{
    struct Lnode* p = L->next;
    while (p)
    {
        visit(p->data);
        if (p->next)
        {
            printf(" ");
        }
        p = p->next;
    }
    printf("\n");
}// ListTraverse_L

Status DestroyList_L(LinkList L) {
    struct Lnode* cp = L->next;
    struct Lnode* np;
    while (cp != NULL) {         //遍历单链表,向系统交回每一个结点
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
    while (cp != NULL) {          //遍历单链表,向系统交回每一个结点
        np = cp->next;            //保存下一个结点的指针 
        free(cp);                   //删除当前结点
        cp = np;                     //使下一个结点成为当前结点 
    }
    L->next = NULL;             //置单链表为空 
    return OK;
}
void MergeList_L(LinkList La, LinkList Lb, LinkList Lc)
{

    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc;
    Lc = pc = La;             //用La的头结点作为Lc的头结点 
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa; pc = pa; pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
        pc->next = pa ? pa : pb;    //插入剩余段  
        free(Lb);                    //释放Lb的头结点  
}
int main()
{
    struct Lnode* La = InitList_L();
    struct Lnode* Lb = InitList_L();
    struct Lnode* Lc = InitList_L();
    int n, i = 1;
    scanf("%d", &n);
    while (n != -1)
    {
        ListInsert_L(La, i, n);
        scanf("%d", &n);
        i++;
    }
    i = 1;
    scanf("%d", &n);
    while (n != -1)
    {
        ListInsert_L(Lb, i, n);
        scanf("%d", &n);
        i++;
    }
    MergeList_L(La, Lb, Lc);
    ListTraverse_L(La);
   
}