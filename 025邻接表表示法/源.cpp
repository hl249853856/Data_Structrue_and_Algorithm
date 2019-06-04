//ͼ���ڽӱ��ʾ��
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define MaxVertexNum 100	//��󶥵���100
using std::queue;

typedef int Vertex;	//�ö����±��ʾ���㣬Ϊ����
typedef int WeightType;	//�ߵ�Ȩֵ��Ϊ����
typedef char DataType;	//����洢����������Ϊ�ַ���

//�ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;	//�����<V1,V2>
	WeightType Weight;//Ȩ��
};
typedef PtrToENode Edge;

//�ڽӵ�Ķ���
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;//�ڽӵ��±�
	WeightType Weight;//��Ȩ��
	PtrToAdjVNode Next;//ָ����һ���ڽӵ��ָ��
};

//�����ͷ���Ķ���
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;//�߱�ͷָ��
	DataType Data;		//�涥�������
	//ע�⣺�ܶ�����£����������ݣ���ʱData���Բ��ó���
}AdjList[MaxVertexNum];	//AdjList���ڽӱ�����

//ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;	//������
	int Ne;	//����
	AdjList G;	//�ڽӱ�
};
typedef PtrToGNode LGraph;	//���ڽӱ�ʽ�洢��ͼ����

LGraph CreateGraph(int VertexNum)
{
	//��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(GNode));//����ͼ
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	//��ʼ���ڽӱ�ͷָ��
	//ע�⣺����Ĭ�϶����Ŵ�0��ʼ������Graph->Nv-1��
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	//�����<V1,V2>
	//ΪV2�����µ��ڽӵ�
	NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	//��V2����V1�ı�ͷ
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	//��������ͼ����Ҫ�����<V2,V1>
	//ΪV1�����µ��ڽӵ�
	NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	//��V1����V2�ı�ͷ
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);	//���붥�����
	Graph = CreateGraph(Nv);	//��ʼ����Nv�����㵫û�бߵ�ͼ

	scanf("%d", &(Graph->Ne));	//�������
	if (Graph->Ne != 0) {
		//����б�
		E = (Edge)malloc(sizeof(ENode));//�����߽��
		//����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ���
		for (i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			//ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ��
			InsertEdge(Graph, E);
		}
	}
		//������������ݵĻ�����������
		for (V = 0; V < Graph->Nv; V++)
			scanf(" %c", &(Graph->G[V].Data));

		return Graph;
}


//DFS---��ͨͼ
void DFS(LGraph Graph, int V)
{
	int visited[MaxVertexNum];
	for (int i = 0; i < Graph->Nv; i++)
		visited[i] = false;
	visited[V] = true;
	printf("%d ", Graph->G[V].Data);
	AdjVNode* p = Graph->G[V].FirstEdge;
	while (p)
	{
		if(!visited[p->AdjV])
			DFS(Graph, p->AdjV);
		p = p->Next;
	}	
}

//����ͨͼ
void DFSTraversae(LGraph Graph)
{
	int i;
	int visited[MaxVertexNum];
	for (i = 0; i < Graph->Nv; i++)
		visited[i] = false;
	for (i = 0; i < Graph->Nv; i++)
		if (!visited[i])
			DFS(Graph, i);
}

//BFS
void BFS(LGraph Graph, int V)
{
	queue<int> Q;
	AdjVNode* p;
	int visited[MaxVertexNum];
	for (int i = 0; i < Graph->Nv; i++)
		visited[i] = false;
	visited[V] = true;
	Q.push(V);
	while (!Q.empty()) {
		V = Q.front();
		Q.pop();
		printf("%d ", Graph->G[V].Data);
		p = Graph->G[V].FirstEdge;
		while (p) {
			if (!visited[p->AdjV])
			{
				visited[p->AdjV] = true;
				Q.push(p->AdjV);
			}
			p = p->Next;
		}
	}
}