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
Status BiTreeEmpty(BiTree T)
{
	if (T)
		return FALSE;
	else
		return TRUE;
}
struct BiTNode* CreateBinTree()
{
	int data;
	struct BiTNode* BinTree, * Temp;
	struct BiTNode* Queue[100];
	int head = 0, tail = 0;
	data = temp[treeIndex++];
	if (data == -1||treeIndex>j)
		return NULL;
	else {
		BinTree = (struct BiTNode*)malloc(sizeof(struct BiTNode));
		BinTree->data = data;
		BinTree->lchild = NULL;
		BinTree->rchild = NULL;
		Queue[tail++] = BinTree;
	}
	while (head < tail) {
		data = temp[treeIndex++];
		if (data == -1||treeIndex>j) {
			Queue[head]->lchild = NULL;//空节点不入队
		}
		else {
			Temp = (struct BiTNode*)malloc(sizeof(struct BiTNode));
			Temp->data = data;
			Temp->lchild = NULL;
			Temp->rchild = NULL;
			Queue[head]->lchild = Temp;
			Queue[tail++] = Temp;
		}
		data = temp[treeIndex++];
		if (data == -1||treeIndex>j) {
			Queue[head]->rchild = NULL;//空节点不入队
		}
		else {
			Temp = (struct BiTNode*)malloc(sizeof(struct BiTNode));
			Temp->data = data;
			Temp->lchild = NULL;
			Temp->rchild = NULL;
			Queue[head]->rchild = Temp;
			Queue[tail++] = Temp;
		}
		head++;
	}
	return BinTree;
}
void FloorPrint(BiTree Tree)  //层序遍历
{
	number = 0;
	BiTree temp2[100];   //创建pTreeNode指针类型的指针数组
	int in = 0;
	int out = 0;

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
void Delete(BiTree& T)
{
	if (T->lchild)Delete(T->lchild);
	if (T->rchild)Delete(T->rchild);
	if (T->lchild&&T->lchild->data == 0 && !T->lchild->lchild && !T->lchild->rchild) {
		T->lchild = NULL;
	}
	if (T->rchild&&T->rchild->data == 0 && !T->rchild->lchild && !T->rchild->rchild) {
		T->rchild = NULL;
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
					temp2 = i*temp2 +  (c - '0');
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
	T=CreateBinTree();
	Delete(T);
	FloorPrint(T);
	for (int i = 0; i < number; i++)
	{
		if (temp[i] == -1 && temp[i + 1] == -1) {
			number = i-1; break;
		}
	}
	printf("[");
	for (int i = 0; i < number; i++)
	{
		if (temp[i] == 0 || temp[i] == 1)printf("%d,",temp[i]);
		else printf("null,");
	}
	if (temp[number] == 0 || temp[number] == 1)printf("%d",temp[number]);
	else printf("null");
	printf("]\n");
}