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
	scanf("%d %d", &G->numNodes, &G->numEdges); /* 输入顶点数和边数 */
	for (i = 0; i < G->numNodes; i++) /* 读入顶点信息,建立顶点表 */
		G->vexs[i]='a';
	for (i = 0; i < G->numNodes; i++)
		for (j = 0; j < G->numNodes; j++)
			G->arc[i][j] = GRAPH_INFINITY;	/* 邻接矩阵初始化 */
	for (k = 0; k < G->numEdges; k++) /* 读入numEdges条边，建立邻接矩阵 */
	{
		scanf("%d %d", &i, &j); /* 输入边(vi,vj)上的权w */
		w = 1;
		G->arc[i-1][j-1] = w;
		G->arc[j-1][i-1] = G->arc[i-1][j-1]; /* 因为是无向图，矩阵对称 */
	}
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	int j = 0,order=0;
	while (1)
	{
		for (int i = G.numNodes-1; i >=-1 ; i--)
		{
			if (i == -1) {
				order = 1; break;
			}
			if (G.arc[j][i] != GRAPH_INFINITY) {
				G.arc[j][i] = GRAPH_INFINITY;
				G.arc[i][j] = GRAPH_INFINITY;
				j = i;
				break;
			}
		}
		if (order == 1)break;
	}
	for (int i = 0; i < G.numNodes; i++)
	{
		for (int j = 0; j < G.numNodes; j++)
		{
			if (G.arc[i][j] != GRAPH_INFINITY) {
				printf("0\n"); return 0;
			}
		}
	}
	printf("1\n");
	return 0;
}
