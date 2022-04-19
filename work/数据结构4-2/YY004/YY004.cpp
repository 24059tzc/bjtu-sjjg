#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int Status;
typedef int SElemType;
/*定义链表栈*/
typedef struct SNode {
    SElemType data;
    struct SNode* next;
}StackNode, * LinkNode;
typedef struct
{
    LinkNode top;//栈顶指针
    int size;
}LinkStack;
//初始化链表
Status InitLinkStack(LinkStack& LS)//构造空栈
{
    LS.top = (LinkNode)malloc(sizeof(SNode));//栈顶指针申请存储空间
    LS.top->next = NULL;
    LS.size = 0;//空栈
    return OK;
}
Status Push(LinkStack& LS, SElemType e)//进栈
{
    LinkNode p = (LinkNode)malloc(sizeof(SNode));
    p->next = LS.top->next;
    LS.top->next = p;
    p->data = e;
    ++LS.size;//栈长+1
    return OK;
}
Status Pop(LinkStack& LS, SElemType& e)//出栈
{
    if (LS.size == 0)//判空
    {
        return ERROR;
    }
    e = LS.top->next->data;//栈顶下一个指针的数据域
    LinkNode p = LS.top->next;
    LS.top->next = LS.top->next->next;
    --LS.size;//栈长-1
    free(p);//释放指针p的空间
    return OK;
}
Status GetTop(LinkStack& LS, SElemType& e) {
    if (LS.size == 0)//判空
    {
        return ERROR;
    }
    e = LS.top->next->data;
    return OK;
}
Status StackEmpty(LinkStack LS)
{
    if (LS.size == 0)//判空
        return OK;
    else
    {
        return ERROR;
    }
}
int main()
{
    LinkStack S1, S2;
    InitLinkStack(S1);
    int N1, N2;
    InitLinkStack(S2);
    char c;
    int n, temp;
    int i, j;
    scanf("%d %d", &N1, &N2);
    if (N1 > N2)
    {
        temp = N1;
        N1 = N2;
        N2 = temp;
    }
    c = getchar();
    while (true)
    {
        if (c == ' ' || c == '\n') {
            c = getchar(); continue;
        }
        if (c == 'A')
        {
            scanf(" %d", &n);
            if (S1.size < N1)  Push(S1, n);
            else if (S1.size == N1 && S2.size == 0) {
                while (S1.size != 0) {
                    Pop(S1, temp); Push(S2, temp);
                }
                Push(S1, n);
            }
            else if (S1.size == N1 && S2.size != 0) printf("ERROR:Full\n");
        }
        else if (c == 'D')
        {
            if (S1.size == 0 && S2.size == 0)
            {
                printf("ERROR:Empty\n");
            }
            else if (S2.size != 0)
            {
                Pop(S2, n);
                printf("%d\n", n);
            }
            else if (S2.size == 0)
            {
                while (S1.size != 0) {
                    Pop(S1, temp); Push(S2, temp);
                }
                Pop(S2, n);
                printf("%d\n", n);
            }
        }
            else
            {
                break;
            }
        c = getchar();
    }
}