#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */
typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int TElemType;
/* 用于构造二叉树********************************** */
int treeIndex = 0;
int temp[100];
int j;
int number;
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
/* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
void DestroyBiTree(BiTree* T)
{
	if (*T)
	{
		if ((*T)->lchild) /* 有左孩子 */
			DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
		if ((*T)->rchild) /* 有右孩子 */
			DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
		free(*T); /* 释放根结点 */
		*T = NULL; /* 空指针赋0 */
	}
}
void createBitree(BiTree* root, int index) {
	if (temp[index - 1] == -1 || index > j) {
		*root = NULL;
	}
	else {
		*root = (BiTree)malloc(sizeof(BiTNode));
		(*root)->data = temp[index - 1];
		createBitree(&((*root)->lchild), 2 * index);
		createBitree(&((*root)->rchild), 2 * index + 1);
	}
}
/* 初始条件: 二叉树T存在 */
/* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
Status BiTreeEmpty(BiTree T)
{
	if (T)
		return FALSE;
	else
		return TRUE;
}
/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
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
/* 初始条件: 二叉树T存在 */
/* 操作结果: 前序递归遍历T */
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%d", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}
/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
	printf("%d", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}
/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序递归遍历T */
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild); /* 先后序遍历左子树  */
	PostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
	printf("%d", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
}
void findancestor(BiTree T, BiTree u, int a, int* a_ancestor)
{
	if ((T->lchild) && T->lchild->data == a || (T->rchild) && T->rchild->data == a)
	{
		a_ancestor[number] = T->data;
		number++;
		a_ancestor[0]++;
		findancestor(u, u, T->data, a_ancestor);
	}
	else {
		if (T->lchild)findancestor(T->lchild, u, a, a_ancestor);
		if (T->rchild)findancestor(T->rchild, u, a, a_ancestor);
	}
}
int main()
{
	int  i = 1, temp2 = 0;
	j = 0;
	int p, q;
	BiTree T;
	InitBiTree(&T);
	char c = getchar();
	while (1)
	{
		if (c == 'r' || c == 'o' || c == 't' || c == ' ' || c == '=')
		{
			c = getchar();
			continue;
		}
		else if (c == ',' || c == '[')
		{
			c = getchar();
			while (1)
			{
				if (c == ']' || c == ',')
				{
					temp[j] = temp2;
					i = 1;
					j++;
					temp2 = 0;
					break;
				}
				else if (c == 'n')
				{
					temp[j] = -1;
					j++;
					for (int k = 0; k <= 4; k++)
						c = getchar();
					continue;
				}
				else if (c >= '0' && c <= '9')
				{
					temp2 = temp2 + i * (c - '0');
					i = i * 10;
				}
				c = getchar();
			}
		}
		if (c == ']')
		{
			break;
		}
	}
	for (int k = 0; k < 4; k++)
	{
		c = getchar();
	}
	scanf("%d", &p);
	for (int k = 0; k < 4; k++)
	{
		c = getchar();
	}
	scanf("%d", &q);
	createBitree(&T, 1);
	number = 2;
	int a_ancestor[100];
	a_ancestor[1] = p;
	a_ancestor[0] = 1;
	findancestor(T, T, p, a_ancestor);
	number = 2;
	int b_ancestor[100];
	b_ancestor[1] = q;
	b_ancestor[0] = 1;
	findancestor(T, T, q, b_ancestor);
	for (int ii = 1; ii <= a_ancestor[0]; ii++)
	{
		for (int jj = 1; jj <= b_ancestor[0]; jj++)
		{
			if (a_ancestor[ii] == b_ancestor[jj]) {
				printf("%d\n", a_ancestor[ii]); ii = a_ancestor[0] + 1; break;
			}
		}
	}
}