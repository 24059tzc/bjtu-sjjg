#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef char SElemType;

/*定义链表栈*/
typedef struct SNode {
    SElemType data;
    struct SNode* next;
}StackNode, *LinkNode;
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

Status Pop(LinkStack &LS, SElemType& e)//出栈
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
//检查两个括号是否匹配
Status match(char element_l, char element_r) {
    if (element_l == '(') {
        if (element_r == ')') {
            return TRUE;
        }
        else {
            return FALSE;
        }
    }
    else if (element_l == '[') {
        if (element_r == ']') {
            return TRUE;
        }
        else {
            return FALSE;
        }
    }
    else if (element_l == '{') {
        if (element_r == '}') {
            return TRUE;
        }
        else {
            return FALSE;
        }
    }
    else {
        exit(0);
    }
}


int main() {
    LinkStack S;
    int i = 0;
    char e;
    int lenth = 0;
    char str[MAXSIZE];
    InitLinkStack(S);
    scanf("%s", str);//输入一串括号
    lenth = strlen(str);
    for (i = 0; i < lenth; i++) {
        switch (str[i]) {
        case '(':
        case '[':
        case '{':
            Push(S, str[i]);
            break;
        case ')':
        case ']':
        case '}':
            if (TRUE ==StackEmpty(S)) {
                printf("右括号多余\n");
                exit(0);
            }
            else {
                GetTop(S, e);
                if (TRUE == match(e, str[i])) {
                    Pop(S, e);
                }
                else {
                    printf("左右括号不匹配\n");
                    exit(0);
                }
            }
            break;
        default:
            exit(0);
        }
    }
    if (TRUE == StackEmpty(S)) {
        printf("括号匹配\n");
    }
    else {
        printf("左括号多余\n");
        exit(0);
    }
    return 0;
}