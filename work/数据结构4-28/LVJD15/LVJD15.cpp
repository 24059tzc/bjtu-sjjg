#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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
int a[100][2];
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
Status Delete(BiTree& T,BiTree& TT,int target)
{
	if (!T)return 1;
	if (T->lchild&&T->lchild->data == target && !T->lchild->lchild && !T->lchild->rchild) {
		T->lchild = NULL; Delete(TT, TT, target);
	}
	if (!T)return 1;
	if (T->rchild&&T->rchild->data == target && !T->rchild->lchild && !T->rchild->rchild) {
		T->rchild = NULL; Delete(TT, TT, target);
	}
	if (!T)return 1;
	if (T->lchild&&(T->lchild->lchild||T->lchild->rchild))
	{
		Delete(T->lchild, TT, target);
	}
	if (!T)return 1;
	if (T->rchild&&(T->rchild->lchild || T->rchild->rchild))
	{
		Delete(T->rchild, TT, target);
	}
	if (!T)return 1;
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
	for (int i = 0; i < 9; i++)
	{
		c = getchar();
	}
	int target;
	scanf("%d", &target);
	T = CreateBinTree();
	number = 0;
	int sum = 0;
	Delete(T, T, target);
	for (int i = 0; i < 100; i++)
	{
		temp[i] = -1;
	}
	FloorPrint(T);
	if (T->data == target && !T->lchild && !T->rchild) {
		temp[0] = -1; number = 0;
	}
	printf("[");
	for (int i = 99; i >= 0; i--)
	{
		if (temp[i] !=-1) {
			number = i; break;
		}
	}
	if (number == 0 && temp[0] == -1) { printf("]\n"); return 0; }
	for (int i = 0; i < number; i++)
	{
		if (temp[i] != -1 )printf("%d,", temp[i]);
		else printf("null,");
	}
	if (temp[number] != -1 )printf("%d", temp[number]);
	else printf("null");
	printf("]\n");
}