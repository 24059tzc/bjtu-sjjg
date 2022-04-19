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
Status Delete(BiTree& T, BiTree& TT, int target)
{
	if (!T)return 1;
	if (T->lchild && T->lchild->data == target && !T->lchild->lchild && !T->lchild->rchild) {
		T->lchild = NULL; Delete(TT, TT, target);
	}
	if (!T)return 1;
	if (T->rchild && T->rchild->data == target && !T->rchild->lchild && !T->rchild->rchild) {
		T->rchild = NULL; Delete(TT, TT, target);
	}
	if (!T)return 1;
	if (T->lchild && (T->lchild->lchild || T->lchild->rchild))
	{
		Delete(T->lchild, TT, target);
	}
	if (!T)return 1;
	if (T->rchild && (T->rchild->lchild || T->rchild->rchild))
	{
		Delete(T->rchild, TT, target);
	}
	if (!T)return 1;
}
double* averageOfLevels(struct BiTNode * root, int* returnSize) {
	struct BiTNode* node[20000];   //存储每层的节点
	double average[10000];          //存储每行平均值
	int num1 = 0, num2 = 0, k = 0, all = 0;
	//第num1行第num2个节点，整棵树第all个节点
	double temp = 0;

	if (root)
	{
		node[0] = root;
		k++;
		num2++;
		average[all++] = root->data;
	}								//初始化

	while (num1 != num2)            //需要遍历下一行
	{
		if (node[num1]->lchild)
			node[num2++] = node[num1]->lchild;
		if (node[num1]->rchild)
			node[num2++] = node[num1]->rchild;
		num1++;					    //遍历完当前行

		if (num1 == k && k != num2) //n作为求和判断条件
		{
			k = num2;
			for (int n = 0; n < num2 - num1; n++)
				temp += node[n + num1]->data;
			average[all++] = temp / (num2 - num1);
			temp = 0;
		}
	}

	double* out = (double*)malloc(all * sizeof(double));
	for (int n = 0; n < all; n++)
		out[n] = average[n];
	*returnSize = all;

	return out;
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
					temp2 = i*temp2 +(c - '0');
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
	double* aaa = (double*)malloc(100 * sizeof(double));
	int aaaa;
	aaa=averageOfLevels(T, &aaaa);
	number = 0;
	int sum = 0;
	
	
	printf("[");
	for (int i = 0; i < aaaa; i++)
	{
		if (i!=aaaa-1)printf("%g,", aaa[i]);
		else printf("%g",aaa[i]);
	}
	printf("]\n");
}