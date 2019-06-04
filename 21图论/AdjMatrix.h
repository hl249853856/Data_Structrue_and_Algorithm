#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100


//�ڽӾ����ʾͼ
typedef struct GNode *PtrToNode;
typedef PtrToNode MGraph;
struct GNode {
	int Nv;		//������
	int Ne;		//����
	int G[MaxVertexNum][MaxVertexNum];	//Ȩ�ؾ���
};

typedef int Vertex;
//��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
MGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	//ע�⣺����Ĭ�϶����Ŵ�0��ʼ������Graph->Nv-1��
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = 0;

	return Graph;
}

typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;		//�����<V1,V2>
	int Weight;			//Ȩ��
};

typedef PtrToENode Edge;

void InserEdge(MGraph Graph, Edge E)
{
	//�����<V1,V2>
	Graph->G[E->V1][E->V2] = E->Weight;
	//��������ͼ����Ҫ�����<V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;
}