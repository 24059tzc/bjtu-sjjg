#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char TElemType;
/* 用于构造二叉树********************************** */
int treeIndex = 0;
typedef char String[24]; /*  0号单元存放串的长度 */
String str;
int temp[100];
int j;
int number;
int a[100][2];

Status StrAssign(String T, char* chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)
		return ERROR;
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}
/* ************************************************ */

Status visit(TElemType e)
{
	printf("%d ", e);
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

/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树T。 */
void CreateBiTree(BiTree* T)
{
	TElemType ch;
	ch = getchar();
	if (ch == '0')
	{
	  	getchar();
		*T = NULL;
	}
	else if (ch == '-')
	{
		getchar();
		getchar();
		return;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(0);
		(*T)->data = ch; /* 生成根结点 */
		getchar();
		CreateBiTree(&(*T)->lchild); /* 构造左子树 */
		CreateBiTree(&(*T)->rchild); /* 构造右子树 */
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

#define ClearBiTree DestroyBiTree

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

/* 初始条件: 二叉树T存在。操作结果: 返回T的根 */
TElemType Root(BiTree T)
{
	if (BiTreeEmpty(T))
		return ERROR;
	else
		return T->data;
}

/* 初始条件: 二叉树T存在，p指向T中某个结点 */
/* 操作结果: 返回p所指结点的值 */
TElemType Value(BiTree p)
{
	return p->data;
}

/* 给p所指结点赋值为value */
void Assign(BiTree p, TElemType value)
{
	p->data = value;
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 前序递归遍历T */
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
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
	printf("%c", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
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
	printf("%c", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
}
void FloorPrint(BiTree Tree)  //层序遍历
{
	number = 0;
	BiTree temp2[100];   //创建pTreeNode指针类型的指针数组
	int in = 0;
	int out = 0;
	if (!Tree)return;
	temp2[in++] = Tree;  //先保存二叉树根节点 

	while (in > out)
	{
		if (temp2[out])
		{
			temp[number++] = temp2[out]->data;
			temp2[in++] = temp2[out]->lchild;
			temp2[in++] = temp2[out]->rchild;
		}
		else temp[number++] = -1;
		out++;
	}
}
void FloorPrint(BiTree Tree,int& number,int *temp)  //层序遍历
{
	number = 0;
	BiTree temp2[100];   //创建pTreeNode指针类型的指针数组
	int in = 0;
	int out = 0;
	if (!Tree)return;
	temp2[in++] = Tree;  //先保存二叉树根节点 

	while (in > out)
	{
		if (temp2[out])
		{
			temp[number++] = temp2[out]->data-'0';
			temp2[in++] = temp2[out]->lchild;
			temp2[in++] = temp2[out]->rchild;
		}
		else temp[number++] = -1;
		out++;
	}
}
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int ELemtype;
typedef struct BiTNode
{
	ELemtype data;
	struct BiTNode* lchild, * rchild;
}BiNode, * Bitree;
void Create(Bitree* T)
{
	ELemtype n;
	scanf("%d", &n);
	if (n == -1) return;
	if (n == 0) {
		*T = NULL;
	}
	else {
		*T = (Bitree)malloc(sizeof(BiNode));
		(*T)->data = n;
		Create(&(*T)->lchild);
		Create(&(*T)->rchild);
	}
}
void ListBiTree(Bitree T) {
	if (T != NULL) {
		printf("%d", T->data);
		if (T->lchild != NULL || T->rchild != NULL) {
			printf("(");
			ListBiTree(T->lchild);
			if (T->rchild != NULL)
				printf(",");
			ListBiTree(T->rchild);
			printf(")");
		}
	}
}
Bitree Merge(Bitree a, Bitree b)
{
	if (b == NULL) return a;
	if (a == NULL) return b;
	if (!a && !b) return NULL;
	a->data += b->data;
	a->lchild = Merge(a->lchild, b->lchild);
	a->rchild = Merge(a->rchild, b->rchild);
	return a;
}
int main()
{
	Bitree Ta, Tb, Tc;
	int x;
	Create(&Ta);
	scanf("%d", &x);
	Create(&Tb);
	Tc = Merge(Ta, Tb);
	ListBiTree(Tc);
	printf("\n");
}

