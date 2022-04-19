﻿#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
#define GRAPH_INFINITY 65535 /* 用65535来代表∞ */
#define INFINITY 65535
typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int VertexType; /* 顶点类型应由用户定义  */
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
	int  k, w;
	int i, j;
	scanf("%d", &G->numNodes); /* 输入顶点数和边数 */
	scanf("%d", &G->numEdges);
	for (i = 0; i < G->numNodes; i++) /* 读入顶点信息,建立顶点表 */
		G->vexs[i] = 'A' + i;
	for (i = 0; i < G->numNodes; i++)
		for (j = 0; j < G->numNodes; j++)
			G->arc[i][j] = GRAPH_INFINITY;	/* 邻接矩阵初始化 */
	for (k = 0; k < G->numEdges; k++) /* 读入numEdges条边，建立邻接矩阵 */
	{
		getchar();
		scanf("%d %d", &i, &j); /* 输入边(vi,vj)上的权w */
		scanf("%d", &w);
		G->arc[i-1][j -1] = w;
		G->arc[j - 1][i - 1] = G->arc[i - 1][j - 1];/* 因为是无向图，矩阵对称 */
	}
}
typedef int Vertex;/* 用顶点下标表示顶点,为整形 */
Vertex FindMinDist(MGraph* Graph, int &start, int collected[])
{ /* 返回未被收录顶点中dist最小者 */
	int min = INFINITY,i,j,k=0,m=0;
	for (i = 0; i < Graph->numNodes; i++)
	{
		if (collected[i] != 0)
		{
			for ( j = 0; j < Graph->numNodes; j++)
			{
				if (collected[j] == 0 && Graph->arc[i][j] < min) 
				{
					min = Graph->arc[i][j]; k = j; m = i;
				}
			}
		}
	}
	if (k == 0)return ERROR;
	start = m;
	return k;
//	Vertex MinV, V;
//	int MinDist = INFINITY;
//
//	for (V = 0; V < Graph->numNodes; V++) {
//		if (collected[V] == 0 && dist[V] < MinDist) {
//			/* 若V未被收录，且dist[V]更小 */
//			MinDist = dist[V]; /* 更新最小距离 */
//			MinV = V; /* 更新对应顶点 */
//		}
//	}
//	if (MinDist < INFINITY) /* 若找到最小dist */
//		return MinV; /* 返回对应的顶点下标 */
//	else return ERROR;  /* 若这样的顶点不存在，返回错误标记 */
}
void Dijkstra(MGraph* Graph, int collected[] , Vertex S,int &add)
{

	Vertex V, W;
	int temp;
	/* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
 	for (V = 0; V < Graph->numNodes; V++) {
		collected[V] = 0;
	}
	/* 先将起点收入集合 */
	collected[S] = 1;
	add = 0;
	while (1) {
		/* V = 未被收录顶点中dist最小者 */
		V = FindMinDist(Graph, temp, collected);
		if (V == ERROR) /* 若这样的V不存在 */
			break;      /* 算法结束 */
		collected[V] = 1;  /* 收录V */
		add = add + Graph->arc[temp][V];
	} /* while结束*/
	return; /* 算法执行完毕，返回正确标记 */

}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	int n=0;
	getchar();
	int cost[10];
	int add;
	Dijkstra(&G, cost, n,add);
	int order = 0;
	for (int i = 0; i < G.numNodes; i++)
	{
		if(cost[i] == 0)order=1;
	}
	if (order == 1) {
		printf("Impossible\n"); return 0;
	}
	else printf("%d\n", add);
	return 0;
}
