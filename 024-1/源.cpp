#include<iostream>
#include<vector>
using namespace std;

//�ڽӾ����ʾ��     �����ڳ��ܾ���
class MGraph
{
public:
	MGraph(int V, bool directed)
	{
		this->V = V;
		this->E = 0;
		this->directed = directed;
		//��ʼ���ڽӾ���ͼ
		for (int i = 0; i < V; i++)
			G.push_back(vector<int>(V, 0));
	}

	//���ؽ������
	int VertexNum()
	{
		return V;
	}

	//���رߵĸ���
	int EdgeNum()
	{
		return E;
	}

	//�����
	void InserEdge(int V1, int V2)
	{
		//ȷ�����鲻Խ��
		if (V1 >= V || V1 < 0 || V2 >= V || V2 < 0)
			return;
		//����бߣ�����
		if (hasEdge(V1, V2))
			return;
		G[V1][V2] = 1;
		E++;//������1
		if (directed)
			return;
		else
			G[V2][V1] = 1;
	}

	bool hasEdge(int V1, int V2)
	{
		//��ֹ����Խ��
		if (V1 >= V || V1 < 0 || V2 >= V || V2 < 0)
			return false;
		return G[V1][V2];
	}

	~MGraph() {}
private:
	int V, E;//VΪͼ�Ľ�������EΪͼ�ı���
	bool directed;//�Ƿ�Ϊ����ͼ
	vector<vector<int>> G;//�ڽӾ���
};


//�ڽӱ��ʾ��    ������ϡ�����
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

	//���ض������
	int VertexNum()
	{
		return V;
	}

	//���ر߸���
	int EdgeNum()
	{
		return E;
	}

	void InsertEdge(int V1, int V2)
	{
		//��ֹ����Խ��
		if (V1 >= V || V1 < 0 || V2 >= V || V2 < 0)
			return;
		G[V1].push_back(V2);
		E++;
	}

	bool hasEdge(int V1, int V2)
	{
		//��ֹ����Խ��
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
	int V, E;//VΪͼ�Ľ�������EΪͼ�ı���
	bool directed;//�Ƿ�Ϊ����ͼ
	vector<vector<int>> G;//�ڽӱ�
};