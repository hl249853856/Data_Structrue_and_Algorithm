#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100


//邻接矩阵表示图
typedef struct GNode *PtrToNode;
typedef PtrToNode MGraph;
struct GNode {
	int Nv;		//顶点数
	int Ne;		//边数
	int G[MaxVertexNum][MaxVertexNum];	//权重矩阵
};

typedef int Vertex;
//初始化一个有VertexNum个顶点但没有边的图
MGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	//注意：这里默认顶点编号从0开始，到（Graph->Nv-1）
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = 0;

	return Graph;
}

typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;		//有向边<V1,V2>
	int Weight;			//权重
};

typedef PtrToENode Edge;

void InserEdge(MGraph Graph, Edge E)
{
	//插入边<V1,V2>
	Graph->G[E->V1][E->V2] = E->Weight;
	//若是无向图，还要插入边<V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;
}