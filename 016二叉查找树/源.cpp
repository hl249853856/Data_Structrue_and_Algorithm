#include<stdio.h>
#include<stdlib.h>

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


//�ݹ����
Position Find(BinTree BT, int X)
{
	if (!BT) return NULL;
	if (X < BT->Data)
		return Find(BT->Left, X);
	else if (X > BT->Data)
		return Find(BT->Right, X);
	return BT;
}

//��������
Position IterFind(BinTree BT, int X)
{
	while (BT) {
		if (X < BT->Data)
			BT = BT->Left;
		else if (X > BT->Data)
			BT = BT->Right;
		else
			return BT;
	}
	return NULL;
}

//�ݹ������СԪ��
Position FindMin(BinTree BT)
{
	if (!BT) return NULL;
	if (BT->Left == NULL)
		return BT;
	else
		return FindMin(BT->Left);
}

//�������Ԫ��
Position FindMax(BinTree BT)
{
	if (!BT) return NULL;
	while (BT->Right)
		BT = BT->Right;
	return BT;
}

//����,���ظ����
BinTree Insert(BinTree BT, int X)
{
	if (!BT)
		BT = new TreeNode(X);
	else if (X < BT->Data)
		BT->Left = Insert(BT->Left, X);
	else if (X > BT->Data)
		BT->Right = Insert(BT->Right, X);
	//else X�Ѵ��ڣ�ʲô������

	return BT;
}

//ɾ��
//Ҫɾ���Ľ����������������ʱ������һ����������ɾ�����
//ʹ������������СԪ�ػ������������Ԫ��
BinTree Delete(BinTree BT, int X)
{
	Position Tmp;
	if (!BT)
		printf("��Ϊ��");
	else if (X < BT->Data)
		BT->Left = Delete(BT->Left, X);
	else if (X > BT->Data)
		BT->Right = Delete(BT->Right, X);
	else {
		if (BT->Left&&BT->Right) {
			Tmp = FindMin(BT->Right);
			BT->Data = Tmp->Data;
			BT->Right = Delete(BT->Right, X);
		}
		else {
			Tmp = BT;
			if (!BT->Left)	//������Ϊ��
				BT = BT->Right;
			if (!BT->Right)	//������Ϊ��
				BT = BT->Left;
		}
	}
	return BT;
}