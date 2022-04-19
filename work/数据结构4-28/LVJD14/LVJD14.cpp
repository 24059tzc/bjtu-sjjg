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
struct BiTNode* CreateBinTree()
{
	int data;
	struct BiTNode* BinTree, * Temp;
	struct BiTNode* Queue[100];
	int head = 0, tail = 0;
	data = temp[treeIndex++];
	if (data == -1 || treeIndex > j)
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
		if (data == -1 || treeIndex > j) {
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
		if (data == -1 || treeIndex > j) {
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
/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
	temp[number++] = T->data;/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
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
	T = CreateBinTree();
	number = 0;
	InOrderTraverse(T);
	printf("[");
	for (int i = 0; i < number - 1; i++)
	{
		if (temp[i] != -1)printf("%d,", temp[i]);
	}
	if (temp[number - 1] != -1)printf("%d", temp[number - 1]);
	printf("]\n");
}