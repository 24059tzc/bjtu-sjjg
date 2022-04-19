#include<stdio.h>
#include<stdlib.h>
#define INFINITY 65535  //∞设为 65535 
#define MAXVERTEXNUM 100  //最大顶点数设为 100 
typedef struct GNode* PtrToGNode;
struct GNode {
	int Nv;   //顶点数   
	int Ne;   //边数 
	int G[MAXVERTEXNUM][MAXVERTEXNUM];  //邻接矩阵  
	char Data[MAXVERTEXNUM];
};
typedef PtrToGNode MGraph; //以邻接矩阵存储的图类型
MGraph BuildGraph() {
	MGraph Graph;
	int i, j, k, weight;
	char a, b;
	Graph = (PtrToGNode)malloc(sizeof(struct GNode));
	printf("请输入顶点数和边数：");
	scanf("%d %d", &Graph->Nv, &Graph->Ne);
	for (i = 0; i < Graph->Nv; i++)
	{
		getchar();  //getchar()函数是输入一个字符，用此函数将 scanf（）未处理的量 进行释放；      
		printf("请输入第%d 个顶点,数组位置为%d:", i + 1, i);
		scanf("%c", &Graph->Data[i]);  //输入顶点数据   
	}
	for (i = 0; i < Graph->Nv; i++)
		for (j = 0; j < Graph->Nv; j++)
			Graph->G[i][j] = INFINITY;  //初始化邻接矩阵      
	for (k = 0; k < Graph->Ne; k++)
	{
		printf("请输入第%d 条边的顶点信息与边的权值(格式为：起点数据 终点数据 权重):", k + 1);
		getchar();
		scanf("%c %c %d", &a, &b, &weight);
		for (i = 0; Graph->Data[i] != a; i++);   //找到顶点 a 在邻接矩阵中的下标       
		for (j = 0; Graph->Data[j] != b; j++);   //找到顶点 b 在邻接矩阵中的下标               
		Graph->G[i][j] = weight;
		Graph->G[j][i] = weight;
	}
	return Graph;
}
void prim(MGraph Graph)
{
	int con, row;
	int min;
	int parent[Graph->Nv] = { 0 };//保存临接顶点下标的数组，所有顶点parent全部赋值为0，将0号顶点（以0号顶点作为第一个顶点）加入生成树
	int dist[Graph->Nv];//记录当前生成树到剩余顶点的最小权值
	for (row = 1; row < Graph->Nv; row++)
	{
		dist[row] = Graph->G[0][row];//将与下标为0的顶点有边的权值存入dist数组
	}
	printf("\n");
	//核心算法
	for (con = 1; con < Graph->Nv; con++)//只需要循环n-1次，n为顶点的个数
	{
		min = INFINITY;//设置一个最大值来比较权值
		int b, a;
		//找出最小的最小权值min并将下标赋给b
		for (a = 1; a < Graph->Nv; a++)//从1号顶点开始查找
		{
			if (dist[a] != 0 && dist[a] < min)//不在生成树中的顶点且权值最小的
			{
				min = dist[a];//更新最小的权值
				b = a;//更新找到新的顶点下标并赋值给b
			}//a++，执行下一顶点直到a=Graph->Nv跳出循环
		}
		//Graph->Data[parent[b]]为Graph->Data[b]的父母顶点的信息
		printf("（%c %c %d ）", Graph->Data[parent[b]], Graph->Data[b], min);//打印信息
		dist[b] = 0;//将这个顶点加入生成树

		//生成树加入了新的顶点从下标为1的顶点开始更新parent数组值
		for (a = 1; a < Graph->Nv; a++)
		{
			if (dist[a] != 0 && Graph->G[b][a] < dist[a])//如果新加入树的顶点b使得权值变小
			{
				dist[a] = Graph->G[b][a];//更新最小的权值
				parent[a] = b;//修改这条边邻接的顶点，也就是表示这条边是从选出的顶点b指过来的，方便打印
			}
		}
	}
}
void Trav(MGraph Graph)//打印邻接矩阵的顶点到顶点之间的权值 
{
	for (int i = 0; i < Graph->Nv; i++)
	{
		for (int t = 0; t < Graph->Nv; t++)
		{
			printf("%5d ", Graph->G[i][t]);
		}
		printf("\n");
	}
}
int main()
{
	MGraph MG = BuildGraph();//创建邻接矩阵 
	//Trav(MG);//遍历邻接矩阵 
	prim(MG);//最小生成树的生成 
	printf("\n");
	system("pause");
	return 0;
}
