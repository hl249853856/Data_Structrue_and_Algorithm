//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define MaxVertexNum 100	//��󶥵�����Ϊ100
#define INFINITY 65535
using std::queue;

typedef int Vertex;	//�ö����±��ʾ���㣬Ϊ����
typedef int WeightType;//�ߵ�Ȩֵ��Ϊ����
typedef char DataType;	//����洢������������Ϊ�ַ���

//�ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;	//�����<V1,V2>
	WeightType Weight;//Ȩ��
};
typedef PtrToENode Edge;

//ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;	//������
	int Ne;	//����
	WeightType G[MaxVertexNum][MaxVertexNum];	//�ڽӾ���
	DataType Data[MaxVertexNum];	//�涥�������
	//ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó���
};
typedef PtrToGNode MGraph;	//���ڽӾ���洢��ͼ����

MGraph CreateGraph(int VertexNum)
{
	//��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(GNode));//����ͼ
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	//��ʼ���ڽӾ���
	//ע�⣺����Ĭ�϶����Ŵ�0��ʼ������Graph->Nv-1��
	for (V = 0; V = Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	return Graph;
}

//�����
void InsertEdge(MGraph Graph, Edge E)
{
	//�����<V1,V2>
	Graph->G[E->V1][E->V2] = E->Weight;
	//��������ߣ���Ҫ�����<V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	
	scanf_s("%d", &Nv);//���붥�����
	Graph = CreateGraph(Nv);//��ʼ����Nv�����㵫û�бߵ�ͼ

	scanf_s("%d", &(Graph->Ne));//�������
	
	if (Graph->Ne != 0) {
		//����б�
		E = (Edge)malloc(sizeof(ENode));	//�����߽��
		//����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ���
		for (i = 0; i < Graph->Ne; i++)
		{
			scanf_s("%d %d %d", &E->V1, &E->V2, &E->Weight);
			
			//ע��Ȩ������������ͣ�Weight�����ʽҪ��
			InsertEdge(Graph, E);
		}
	}

	//����ж������ݵĻ������붥������
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



//DFS----��ͨͼ
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

//����ͨͼ
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

//��Ȩͼ��Դ���·��
//dist[]��pathp[ȫ����ʼ��Ϊ-1
void Unweighted(MGraph Graph, int *dist, int *path, int V)
{
	queue<int> Q;
	for (int i = 0; i < Graph->Nv; i++)
	{
		dist[i] = -1;
		path[i] = -1;
	}
	//Դ��Ϊ
	dist[V] = 0;
	Q.push(V);

	while (!Q.empty()) {
		V = Q.front();
		Q.pop();
		for (int j = 0; j < Graph->Nv; j++)
		{
			if (Graph->G[V][j]<INFINITY&&dist[j] == -1)//�����ڵ�δ�����ʹ�
			{
				dist[j] = dist[V] + 1;//���µ�V��j�ľ���
				path[j] = V;//��V��¼��S��j��·��
				Q.push(j);
			}
		}
	}
}



//dijkstra�㷨
int FindMinDist(MGraph Graph, int *dist, int *collected)
{
	//����δ����¼������dist��С��
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
	//��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ
	for (int W = 0; W < Graph->Nv; W++)
	{
		dist[W] = Graph->G[V][W];
		if (dist[W] < INFINITY)
			path[W] = V;
		else
			path[W] = -1;
		collected[W] = false;
	}

	//�Ƚ�������뼯��
	dist[V] = 0;
	collected[V] = true;

	while (1) {
		//W=δ����¼������dist��С��
		W = FindMinDist(Graph, dist, collected);
		if (W == INFINITY)
			break;
		collected[W] = true;//��¼
		for(int X=0;X<Graph->Nv;X++)//��ͼ��ÿ������W
			//��W��V���ڽӵ㲢��δ����¼
			if (collected[X] == false && Graph->G[W][X] < INFINITY)
			{
				if (Graph->G[W][X] < 0)//���и���
					return false;//������ȷ��������ش�����
				if (dist[W] + Graph->G[W][X] < dist[X])
				{
					dist[X] = dist[W] + Graph->G[W][X];//����dist[X]
					path[X] = W;//����V��X�ľ���
				}
			}
	}
	return true;//while����
}

