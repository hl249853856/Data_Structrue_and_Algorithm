#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>

using std::stack;
using std::queue;

struct TreeNode;
typedef struct TreeNode* BinTree;
typedef BinTree Position;

//���������
struct TreeNode {
	int Data;
	BinTree Left;
	BinTree Right;
	TreeNode(int X) :Data(X), Left(NULL), Right(NULL) {}
};

//�������
void PreOrderTraversal(BinTree BT)
{
	if (BT) {
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}

//�������
void InOrderTraversal(BinTree BT)
{
	if (BT) {
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Right);
	}
}

//�������
void PostOrderTraversal(BinTree BT)
{
	if (BT) {
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}

//�������
void LevelOrderTraversal(BinTree BT)
{
	queue<BinTree> Q;
	BinTree T;
	if (!BT)
		return;
	Q.push(BT);
	while (!Q.empty()) {
		T = Q.front();
		Q.pop();
		printf("%d", T->Data);
		if (T->Left)
			Q.push(T->Left);
		if (T->Right)
			Q.push(T->Right);
	}
}

//��������ǵݹ�ʵ��
void InOrderTraversalNo(BinTree BT)
{
	stack<BinTree> S;
	BinTree T = BT;
	while (T || !S.empty()) 
	{
		while (T) {
			S.push(T);
			T = T->Left;
		}
		if (!S.empty()) {
			T = S.top();
			S.pop();
			printf("%d", T->Data);
			T = T->Right;
		}
	}
}

//��������ǵݹ�ʵ��
void PreOrderTraversalNo(BinTree BT)
{
	stack<BinTree> S;
	BinTree T = BT;
	while (T || !S.empty())
	{
		while (T) {
			printf("%d", T->Data);
			S.push(T);
			T = T->Left;
		}
		if (!S.empty()) {
			T = S.top();
			S.pop();
			T = T->Right;
		}
	}
}

//��������ǵݹ�ʵ��
void PostOrderTraversalNo(BinTree BT)
{
	stack<BinTree> S1;
	stack<BinTree> S2;
	BinTree T = BT;
	while (T || !S1.empty())
	{
		if (T) {
			S1.push(T);
			S2.push(T);
			T = T->Right;
		}
		else {
			T = S1.top();
			S1.pop();
			T = T->Left;
		}
	}

	while (!S2.empty()) {
		T = S2.top();
		S2.pop();
		printf("%d", T->Data);
	}
}

//���������������ĸ߶�
int GetHeight(BinTree BT)
{
	int HL, HR, MaxH;
	if (BT) {
		HL = GetHeight(BT->Left);
		HR = GetHeight(BT->Right);
		MaxH = (HL > HR) ? HL : HR;
		return MaxH + 1;
	}
	else
		return 0;
}

int main()
{
	BinTree node1 = new TreeNode(6);
	BinTree node2 = new TreeNode(2);
	BinTree node3 = new TreeNode(8);
	BinTree node4 = new TreeNode(1);
	BinTree node5 = new TreeNode(4);
	BinTree node6 = new TreeNode(3);

	node1->Left = node2;
	node1->Right = node3;
	node2->Left = node4;
	node2->Right = node5;
	node5->Left = node6;

	printf("��������� ");
	PreOrderTraversalNo(node1);
	printf("\n");
	printf("��������� ");
	InOrderTraversalNo(node1);
	printf("\n");
	printf("��������� ");
	PostOrderTraversalNo(node1);
	printf("\n");

	return 0;
}