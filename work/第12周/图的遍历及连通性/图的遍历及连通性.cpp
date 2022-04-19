#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
#define GRAPH_INFINITY 65535 /* 用65535来代表∞ */

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */
typedef struct
{
	VertexType vexs[MAXVEX]; /* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX];/* 邻接矩阵，可看作边表 */
	int numNodes, numEdges; /* 图中当前的顶点数和边数  */
}MGraph;

/* 建立无向网图的邻接矩阵表示 */
void CreateMGraph(MGraph* G)
{
	int i, j, k, w;
	scanf("%d", &G->numNodes); /* 输入顶点数和边数 */
	for (i = 0; i < G->numNodes; i++) /* 读入顶点信息,建立顶点表 */
		G->vexs[i] = 1;
	for (i = 0; i < G->numNodes; i++)
		for (j = 0; j < G->numNodes; j++)
			scanf("%d", &G->arc[i][j]);
}
int design(MGraph G)
{
	int order = 0;
	for (int i = 0; i < G.numNodes; i++)
	{
		if (G.vexs[i] != 0)order++;
	}
	return order;
}
int design(int i, MGraph G)
{
	int order = 0;
	for (int j = i+1; j < G.numNodes; j++)
	{
		if (G.arc[i][j] == 1)order++;
	}
	return order;
}
void Delete(int j, MGraph* G)
{
	for (int i = j + 1; i < G->numNodes; i++)
	{
		if (G->arc[j][i] != 0) {
			G->vexs[j] = 0;
			G->vexs[i] = 0;
			G->arc[j][i] = 0;
			G->arc[i][j] = 0;
			Delete(i, G);
		}
	}
}
int Travel(MGraph* G)
{
	int num=0,i;
	while (design(*G))
	{
		i = 0;
		while (i<G->numNodes)
		{
			if (G->vexs[i] != 0)
			{
				Delete(i, G);
				num++;
				G->vexs[i] = 0;
			}
			i++;
		}
	}
	return num;
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	int num=Travel(&G);
	printf("%d\n", num);
	return 0;
}
