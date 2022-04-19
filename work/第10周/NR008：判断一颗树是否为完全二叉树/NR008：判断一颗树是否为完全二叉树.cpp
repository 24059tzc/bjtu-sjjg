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
	scanf("%c",&ch);
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
/* 初始条件: 二叉树T存在，p指向T中某个结点 */
/* 操作结果: 返回p所指结点的值 */
int number=0, temp[MAXSIZE];
void FloorPrint(BiTree Tree)  //层序遍历
{
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
int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);
	CreateBiTree(&T);
	FloorPrint(T);
	int order = 0;
	for (int i = 0; i < number; i++)
	{
		if (temp[i]==-1)
		{
			order = 1;
		}
		else
		{
			if (order == 1) { printf("No\n"); return 1; }
		}
	}
	printf("Yes\n");
}
