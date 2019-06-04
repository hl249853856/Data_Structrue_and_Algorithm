//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define MaxVertexNum 100	//最大顶点数设为100
#define INFINITY 65535
#define ERROR -100
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

//邻接矩阵BFS
//判断W是否V的邻接点
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}

void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{
	//以S为出发点对邻接矩阵存储的图Graph进行BFS搜索
	queue<Vertex> Q;
	Vertex V, W;


}


//邻接矩阵存储-有权图的单源最短路径算法
Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{
	//返回未被收录的定点中dist最小者
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++)
	{
		if (collected[V] == false && dist[V] < MinDist)
		{
			//若V未被收录，且dist[V]更小
			MinDist = dist[V];//更新最小距离
			MinV = V;//更新对应顶点
		}
	}
	if (MinDist < INFINITY)//若找到最小dist
		return MinV;
	else
		return ERROR;
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	//初始化：此处默认邻接矩阵中不存在的边用INFINITY表示
	for (V = 0; V < Graph->Nv; V++)
	{
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	//先将点收入集合
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		//V=未被收录顶点中dist最小者
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR)//若这样的V不存在
			break;//算法结束
		collected[V] = true;//收录V
		for(W=0;W<Graph->Nv;W++)//对图中的每个顶点W
			//若W是V的邻接点并且未被收录
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0)//若有负边
					return false;//不能正确解决，返回错误标记
				//若收录V使得dist[W]变小
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W];//更新dist[W]
					path[W] = V;//更新S到W的路径
				}
			}
	}//while结束
	return true;//算法执行完毕，返回正确标记
}