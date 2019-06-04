//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define MaxVertexNum 100	//最大顶点数设为100
#define INFINITY 65535
using std::queue;

typedef int Vertex;	//用顶点下标表示顶点，为整型
typedef int WeightType;//边的权值设为整型
typedef char DataType;	//顶点存储的数据类型设为字符型

//边的定义
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;	//有向边<V1,V2>
	WeightType Weight;//权重
};
typedef PtrToENode Edge;

//图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;	//顶点数
	int Ne;	//边数
	WeightType G[MaxVertexNum][MaxVertexNum];	//邻接矩阵
	DataType Data[MaxVertexNum];	//存顶点的数据
	//注意：很多情况下，顶点无数据，此时Data[]可以不用出现
};
typedef PtrToGNode MGraph;	//以邻接矩阵存储的图类型

MGraph CreateGraph(int VertexNum)
{
	//初始化一个有VertexNum个顶点但没有边的图
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(GNode));//建立图
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	//初始化邻接矩阵
	//注意：这里默认顶点编号从0开始，到（Graph->Nv-1）
	for (V = 0; V = Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	return Graph;
}

//插入边
void InsertEdge(MGraph Graph, Edge E)
{
	//插入边<V1,V2>
	Graph->G[E->V1][E->V2] = E->Weight;
	//若是无向边，还要插入边<V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	
	scanf_s("%d", &Nv);//读入顶点个数
	Graph = CreateGraph(Nv);//初始化有Nv个顶点但没有边的图

	scanf_s("%d", &(Graph->Ne));//读入边数
	
	if (Graph->Ne != 0) {
		//如果有边
		E = (Edge)malloc(sizeof(ENode));	//建立边结点
		//读入边，格式为"起点 终点 权重"，插入邻接矩阵
		for (i = 0; i < Graph->Ne; i++)
		{
			scanf_s("%d %d %d", &E->V1, &E->V2, &E->Weight);
			
			//注意权重如果不是整型，Weight读入格式要改
			InsertEdge(Graph, E);
		}
	}

	//如果有顶点数据的话，读入顶点数据
	for (V = 0; V < Graph->Nv; V++)
	{
		scanf_s(" %c", &(Graph->Data[V]));
		
	}
		

	return Graph;
}

int main()
{
	MGraph Graph;
	Graph = BuildGraph();

	return 0;
}



//DFS----连通图
void DFS(MGraph Graph, int V)
{
	int visited[MaxVertexNum];
	for (int i = 0; i < Graph->Nv; i++)
		visited[i] = false;
	visited[V] = true;
	printf("%d ", Graph->Data[V]);
	for (int W = 0; W < Graph->Nv; W++)
		if (Graph->G[V][W] == 1 && !visited[W])
			DFS(Graph, W);
}

//非连通图
void DFSTraverse(MGraph Graph)
{
	int visited[MaxVertexNum];
	for (int i = 0; i < Graph->Nv; i++)
		visited[i] = false;
	for (int i = 0; i < Graph->Nv; i++)
		DFS(Graph, i);
}


//BFS
void BFS(MGraph Graph, int V)
{
	queue<int> Q;
	int visited[MaxVertexNum];
	for (int i = 0; i < Graph->Nv; i++)
		visited[i] = false;
	visited[V] = true;
	Q.push(V);
	while (!Q.empty()) {
		V = Q.front();
		Q.pop();
		printf("%d ", Graph->Data[V]);
		for (int j = 0; j < Graph->Nv; j++)
		{
			if (Graph->G[V][j] == 1 && !visited[j])
			{
				visited[j] = true;
				Q.push(j);
			}
		}
	}
}

//无权图单源最短路径
//dist[]和pathp[全部初始化为-1
void Unweighted(MGraph Graph, int *dist, int *path, int V)
{
	queue<int> Q;
	for (int i = 0; i < Graph->Nv; i++)
	{
		dist[i] = -1;
		path[i] = -1;
	}
	//源点为
	dist[V] = 0;
	Q.push(V);

	while (!Q.empty()) {
		V = Q.front();
		Q.pop();
		for (int j = 0; j < Graph->Nv; j++)
		{
			if (Graph->G[V][j]<INFINITY&&dist[j] == -1)//若其邻点未被访问过
			{
				dist[j] = dist[V] + 1;//更新到V到j的距离
				path[j] = V;//将V记录在S到j的路上
				Q.push(j);
			}
		}
	}
}



//dijkstra算法
int FindMinDist(MGraph Graph, int *dist, int *collected)
{
	//返回未被收录顶点中dist最小者
	int MinDist = INFINITY;
	int MinV;

	for (int V = 0; V < Graph->Nv; V++)
	{
		if (collected[V] == false && dist[V] < MinDist)
		{
			MinDist = dist[V];
			MinV = V;
		}
	}
	if (MinDist < INFINITY)
		return MinV;
	else
		return INFINITY;
}

bool Dijkstra(MGraph Graph, int *dist, int *path, int V)
{
	int collected[MaxVertexNum];
	int W;
	//初始化：此处默认邻接矩阵中不存在的边用INFINITY表示
	for (int W = 0; W < Graph->Nv; W++)
	{
		dist[W] = Graph->G[V][W];
		if (dist[W] < INFINITY)
			path[W] = V;
		else
			path[W] = -1;
		collected[W] = false;
	}

	//先将起点收入集合
	dist[V] = 0;
	collected[V] = true;

	while (1) {
		//W=未被收录顶点中dist最小者
		W = FindMinDist(Graph, dist, collected);
		if (W == INFINITY)
			break;
		collected[W] = true;//收录
		for(int X=0;X<Graph->Nv;X++)//对图中每个顶点W
			//若W是V的邻接点并且未被收录
			if (collected[X] == false && Graph->G[W][X] < INFINITY)
			{
				if (Graph->G[W][X] < 0)//若有负边
					return false;//不能正确解决，返回错误标记
				if (dist[W] + Graph->G[W][X] < dist[X])
				{
					dist[X] = dist[W] + Graph->G[W][X];//更新dist[X]
					path[X] = W;//更新V到X的距离
				}
			}
	}
	return true;//while结束
}

