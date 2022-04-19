#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 500
#define INFINITY 999999
#define ERROR -1

typedef int WeightType;//连接矩阵的类型,权重  
typedef int Vertex;/* 用顶点下标表示顶点,为整形 */
typedef int DataType;/* 数据类型 */

typedef struct GNode* PtrToGNode;//定义point to  GNode的指针 PtrToGNode
struct GNode {
	int Nv; /* 顶点数 */
	int Ne; /* 边数 */
	WeightType G[MaxVertexNum][MaxVertexNum];
	WeightType Cost[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;	/* 以邻接矩阵存储的图的类型  */



typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2; /* 有向边<V1,V2> */
	WeightType Weight;/* 权重 */
	WeightType Cost;
};
typedef PtrToENode Edge; /* 连接线的类型 */

MGraph CreateGraph(int VertexNum);//初始化图 
void InsertEdge(MGraph Graph, Edge E); //插入连接线 
MGraph BuildGraph();
void Dijkstra(MGraph Graph, int cost[], int dist[], Vertex S);
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]);

Vertex start, end;

int main() {
	MGraph Graph = BuildGraph();
	int dist[20], cost[20], i;
	for (i = 0; i < Graph->Nv; i++) {
		dist[i] = INFINITY;
		cost[i] = 0;
	}
	Dijkstra(Graph, cost, dist, start);
	printf("%d %d\n", dist[end], cost[end]);
	return 0;
}

void Dijkstra(MGraph Graph, int cost[], int dist[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	/* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		cost[V] = Graph->Cost[S][V];
		collected[V] = 0;
	}
	/* 先将起点收入集合 */
	dist[S] = 0;
	collected[S] = 1;

	while (1) {
		/* V = 未被收录顶点中dist最小者 */
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) /* 若这样的V不存在 */
			break;      /* 算法结束 */
		collected[V] = 1;  /* 收录V */
		for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
			/* 若W是V的邻接点并且未被收录 */
			if (collected[W] == 0 && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0) /* 若有负边 */
					return; /* 不能正确解决，返回错误标记 */
				/* 若收录V使得dist[W]变小 */
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W]; /* 更新dist[W] */
					cost[W] = cost[V] + Graph->Cost[V][W];
				}
				else if (dist[V] + Graph->G[V][W] == dist[W] &&
					cost[V] + Graph->Cost[V][W] < cost[W]) {
					cost[W] = cost[V] + Graph->Cost[V][W];
				}
			}
	} /* while结束*/
	return; /* 算法执行完毕，返回正确标记 */

}

Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{ /* 返回未被收录顶点中dist最小者 */
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++) {
		if (collected[V] == 0 && dist[V] < MinDist) {
			/* 若V未被收录，且dist[V]更小 */
			MinDist = dist[V]; /* 更新最小距离 */
			MinV = V; /* 更新对应顶点 */
		}
	}
	if (MinDist < INFINITY) /* 若找到最小dist */
		return MinV; /* 返回对应的顶点下标 */
	else return ERROR;  /* 若这样的顶点不存在，返回错误标记 */
}

MGraph CreateGraph(int VertexNum)
{
	MGraph Graph;//先定义一个指向图的指针 
	Vertex V, W;//V和W其实是表示一个顶点，并不是单纯的整数 ，虽然表示出来是一回事 

	Graph = (MGraph)malloc(sizeof(struct GNode));//申请图的内存空间 然后初始化 
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	for (V = 0; V < VertexNum; V++) {//遍历图中的结点,令图中的结点都为0或无穷大,意为没有任何连接 
	//注意上面这里是VertexNum而不是MaxVertexNum,减少多余操作 
		for (W = 0; W < VertexNum; W++) {
			Graph->G[V][W] = INFINITY;/* 或者INFINITY */
		}
	}

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* 插入边<V1,V2> */
	Graph->G[E->V1][E->V2] = E->Weight; /* 有权重的话要等于E->Weight*/
	Graph->Cost[E->V1][E->V2] = E->Cost;

	/* 若是无向图则要反向也插入 */
	Graph->G[E->V2][E->V1] = E->Weight; /* 有权重的话要等于E->Weight*/
	Graph->Cost[E->V2][E->V1] = E->Cost;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Vertex V;
	Edge E;
	int Nv, i;

	scanf("%d", &Nv);//先输入顶点数 
	Graph = CreateGraph(Nv);
	scanf("%d", &(Graph->Ne));//读入边数 
	scanf("%d%d", &start, &end);
	if (Graph->Ne != 0) {
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d%d%d%d", &E->V1, &E->V2, &E->Weight, &E->Cost);
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}