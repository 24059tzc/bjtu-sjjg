#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */
typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
int treeIndex = 1;
typedef char TElemType;
Status visit(TElemType e)
{
	printf("%c ", e);
	return OK;
}
typedef struct BiTNode  /* 结点结构 */
{
	TElemType data;		/* 结点数据 */
	struct BiTNode* lchild, * rchild; /* 左右孩子指针 */
}BiTNode, * BiTree;
/* 构造空二叉树T */
Status InitBiTree(BiTree* T)
{
	*T = NULL;
	return OK;
}
/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树T。 */
void CreateBiTree(BiTree* T)
{
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '0')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(0);
		(*T)->data = ch; /* 生成根结点 */
		CreateBiTree(&(*T)->lchild); /* 构造左子树 */
		CreateBiTree(&(*T)->rchild); /* 构造右子树 */
	}
}
int BiTreeDepth(BiTree T)
{
	int i, j;
	if (!T)
		return 0;
	if (T->lchild)
		i = BiTreeDepth(T->lchild);
	else
		i = 0;
	if (T->rchild)
		j = BiTreeDepth(T->rchild);
	else
		j = 0;
	return i > j ? i + 1 : j + 1;
}
char temp[10];
int order=0,number=0;
void find(BiTree T, int deep)
{
	if (deep > 1 && T->lchild) {
		find(T->lchild, deep - 1);
		if (order == 0 && T->rchild)find(T->rchild, deep - 1);
	}
	else if (deep > 1 && T->rchild)find(T->rchild, deep - 1);
	else if (deep > 1 && (!T->rchild) && (!T->lchild));
	else order = 1;
	if (order == 1)temp[number++] = T->data;
}
int main()
{
	BiTree T;
	TElemType e1;
	InitBiTree(&T);
	CreateBiTree(&T);
	int n = BiTreeDepth(T);
	find(T, n);
	printf("第一条最长的路径长度为: %d\n路径为：", n-1);
	for (int i = number-1; i >= 0; i--)
	{
		printf("%c ->", temp[i]);
	}
	printf("NULL\n");
}
