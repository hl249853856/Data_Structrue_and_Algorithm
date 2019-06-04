#include<iostream>
#include<vector>
using namespace std;

//邻接矩阵表示法     适用于稠密矩阵
class MGraph
{
public:
	MGraph(int V, bool directed)
	{
		this->V = V;
		this->E = 0;
		this->directed = directed;
		//初始化邻接矩阵图
		for (int i = 0; i < V; i++)
			G.push_back(vector<int>(V, 0));
	}

	//返回结点数量
	int VertexNum()
	{
		return V;
	}

	//返回边的个数
	int EdgeNum()
	{
		return E;
	}

	//插入边
	void InserEdge(int V1, int V2)
	{
		//确保数组不越界
		if (V1 >= V || V1 < 0 || V2 >= V || V2 < 0)
			return;
		//如果有边，返回
		if (hasEdge(V1, V2))
			return;
		G[V1][V2] = 1;
		E++;//边数加1
		if (directed)
			return;
		else
			G[V2][V1] = 1;
	}

	bool hasEdge(int V1, int V2)
	{
		//防止数组越界
		if (V1 >= V || V1 < 0 || V2 >= V || V2 < 0)
			return false;
		return G[V1][V2];
	}

	~MGraph() {}
private:
	int V, E;//V为图的结点个数，E为图的边数
	bool directed;//是否为有向图
	vector<vector<int>> G;//邻接矩阵
};


//邻接表表示法    适用于稀疏矩阵
class LGraph
{
public:
	LGraph(int V, bool directed)
	{
		this->V = V;
		this->E = 0;
		this->directed = directed;
		for (int i = 0; i < V; i++)
			G.push_back(vector<int>());
	}

	//返回顶点个数
	int VertexNum()
	{
		return V;
	}

	//返回边个数
	int EdgeNum()
	{
		return E;
	}

	void InsertEdge(int V1, int V2)
	{
		//防止数组越界
		if (V1 >= V || V1 < 0 || V2 >= V || V2 < 0)
			return;
		G[V1].push_back(V2);
		E++;
	}

	bool hasEdge(int V1, int V2)
	{
		//防止数组越界
		if (V1 >= V || V1 < 0 || V2 >= V || V2 < 0)
			return false;
		for (int i = 0; i < G[V].size(); i++)
		{
			if (G[V][i] == V2)
				return true;
		}
		return false;
	}

	~LGraph() {}

private:
	int V, E;//V为图的结点个数，E为图的边数
	bool directed;//是否为有向图
	vector<vector<int>> G;//邻接表
};