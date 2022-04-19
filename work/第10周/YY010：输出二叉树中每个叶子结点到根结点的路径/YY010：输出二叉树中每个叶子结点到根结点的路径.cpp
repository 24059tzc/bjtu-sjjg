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
int order = 0, number = 0;
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
char temp3[10];
int order2=0;
int number3=0;
void findleaf(BiTree T, char c)
{
	if (!T)return;
	else
	{
		if (T->data == c) {
			order2 = 1;
		}
		else
		{
			if (T->lchild)findleaf(T->lchild, c);
			if (order2 == 1);
			else if (T->rchild)findleaf(T->rchild, c);
		}
		if (order2 == 1)temp3[number3++] = T->data;
	}
}
char temp2[10]; int number2 = 0;
int leafSize(BiTree t)
{
	if (!t)return 0;
	if (!t->lchild && !t->rchild)
	{
		temp2[number2++] = t->data;
		return 1;
	}
	else if (!t->lchild)return leafSize(t->rchild);
	else return leafSize(t->lchild) + leafSize(t->rchild);
}
int main()
{
	BiTree T;
	TElemType e1;
	InitBiTree(&T);
	CreateBiTree(&T);
	int n = BiTreeDepth(T);
	find(T, n);
	int m = leafSize(T);
	printf("树中有以下的叶子节点：");
	for (int i = 0; i < number2; i++)
	{
		printf("%c ", temp2[i]);
	}
	printf("\n");
	for (int i = 0; i < number2; i++)
	{
		printf("%c叶子节点到根节点的路径为：", temp2[i]);
		findleaf(T, temp2[i]);
		for (int j = 0; j <number3; j++)
		{
			printf("%c ", temp3[j]);
		}
		order2 = 0; number3 = 0;
		printf("\n");
	}
	printf("最长的路径是：");
	for (int i = 0; i < number; i++)
	{
		printf("%c ", temp[i]);
	}
	printf("\n");
}
