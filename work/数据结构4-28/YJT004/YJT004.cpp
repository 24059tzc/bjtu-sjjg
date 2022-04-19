#include <stdio.h>
#include<stdlib.h>
int c[100],number=0;
int a[100], b[100];
typedef struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
} *Bitree, Node;
Bitree Pre(Bitree T, int* pos, int* in, int n) {
    if (n <= 0) return NULL;
    T = (Bitree)malloc(sizeof(Node));
    T->data = pos[n - 1];
    T->lchild = NULL;
    T->rchild = NULL;
    int i;
    for (i = 0; i < n; ++i)
        if (in[i] == pos[n - 1]) break;
    T->lchild = Pre(T->lchild, pos, in, i);
    T->rchild = Pre(T->rchild, pos + i, in + i + 1, n - i - 1);
    return T;
}
void PreOrderTraverse(Bitree T)
{
    if (T == NULL)
        return;
    c[number] = T->data;
    number++;/* 显示结点数据，可以更改为其它对结点操作 */
    PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
    PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}
int main()
{
    int n;
    Bitree T = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    T=Pre(T, a, b, n);
    PreOrderTraverse(T);
    printf("Preorder: ");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d ", c[i]);
    }
    printf("%d\n", c[n-1]);
}
