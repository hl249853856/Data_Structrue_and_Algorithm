//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define MaxVertexNum 100	//��󶥵�����Ϊ100
#define INFINITY 65535
#define ERROR -100
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

//�ڽӾ���BFS
//�ж�W�Ƿ�V���ڽӵ�
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}

void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{
	//��SΪ��������ڽӾ���洢��ͼGraph����BFS����
	queue<Vertex> Q;
	Vertex V, W;


}


//�ڽӾ���洢-��Ȩͼ�ĵ�Դ���·���㷨
Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{
	//����δ����¼�Ķ�����dist��С��
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++)
	{
		if (collected[V] == false && dist[V] < MinDist)
		{
			//��Vδ����¼����dist[V]��С
			MinDist = dist[V];//������С����
			MinV = V;//���¶�Ӧ����
		}
	}
	if (MinDist < INFINITY)//���ҵ���Сdist
		return MinV;
	else
		return ERROR;
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	//��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ
	for (V = 0; V < Graph->Nv; V++)
	{
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	//�Ƚ������뼯��
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		//V=δ����¼������dist��С��
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR)//��������V������
			break;//�㷨����
		collected[V] = true;//��¼V
		for(W=0;W<Graph->Nv;W++)//��ͼ�е�ÿ������W
			//��W��V���ڽӵ㲢��δ����¼
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0)//���и���
					return false;//������ȷ��������ش�����
				//����¼Vʹ��dist[W]��С
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W];//����dist[W]
					path[W] = V;//����S��W��·��
				}
			}
	}//while����
	return true;//�㷨ִ����ϣ�������ȷ���
}