#include<stdio.h>
#include<stdlib.h>

typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode {
	int Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int Max(int a, int b)
{
	return a > b ? a : b;
}

//�����߶�
int GetHeight(AVLTree BT)
{
	int HL, HR, MaxH;
	if (BT) {
		HL = GetHeight(BT->Left);
		HR = GetHeight(BT->Right);
		MaxH = HL > HR ? HL : HR;
		return MaxH;
	}
	else
		return 0;
}

//����
AVLTree SingleLeftRotation(AVLTree A)
{
	//A������һ�����ӽ��
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = GetHeight(A);
	B->Height = GetHeight(B);

	return B;
}

//�ҵ���
AVLTree SingleRightRotation(AVLTree A)
{
	//A������һ�����ӽ��
	AVLTree B = A->Left;
	A->Right = B->Left;
	B->Left = A;
	A->Height = GetHeight(A);
	B->Height = GetHeight(B);

	return B;
}

//����˫��
AVLTree DoubleLeftRightRotation(AVLTree A)
{
	//A����Ҫ��һ�����ӽ��B��B������һ�����ӽ��C
	//��A��B��C�����ε����������µĸ����C

	//��B��C���ҵ�����C������
	A->Left = SingleRightRotation(A->Left);

	//��A��C��������C������
	return SingleLeftRotation(A);
}

//����˫��
AVLTree DoubleRightLeftRotation(AVLTree A)
{
	//A����Ҫ��һ�����ӽ��B��B������һ�����ӽ��C
	//��A��B��C�����ε����������µĸ����C

	//��B��C��������C������
	A->Right = SingleLeftRotation(A->Right);

	//��A��C���ҵ�����C������
	return SingleRightRotation(A);
}

//AVL����
AVLTree Insert(AVLTree A, int X)
{
	//��Ϊ��ʱ
	if (!A) {
		A = (AVLTree)malloc(sizeof(AVLNode));
		A->Data = X;
		A->Height = 0;
	}
	else if (X < A->Data) {
		//����A��������
		A->Left = Insert(A->Left, X);
		//�����Ҫ����
		if (GetHeight(A->Left) - GetHeight(A->Right) == 2)
			if (X < A->Left->Data)
				A = SingleLeftRotation(A);	//����
			else
				A = DoubleLeftRightRotation(A);	//����˫��
	}
	else if (X > A->Data) {
		//����A��������
		A->Right = Insert(A->Right, X);
		//�����Ҫ����
		if (GetHeight(A->Left) - GetHeight(A->Right) == -2)
			if (X > A->Right->Data)
				A = SingleRightRotation(A);	//�ҵ���
			else
				A = DoubleRightLeftRotation(A);	//����˫��
	}
	//else //X==A->Data���������

	//��������
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;

	return A;
}