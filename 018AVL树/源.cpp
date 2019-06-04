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

//求树高度
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

//左单旋
AVLTree SingleLeftRotation(AVLTree A)
{
	//A必须有一个左子结点
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = GetHeight(A);
	B->Height = GetHeight(B);

	return B;
}

//右单旋
AVLTree SingleRightRotation(AVLTree A)
{
	//A必须有一个右子结点
	AVLTree B = A->Left;
	A->Right = B->Left;
	B->Left = A;
	A->Height = GetHeight(A);
	B->Height = GetHeight(B);

	return B;
}

//左右双旋
AVLTree DoubleLeftRightRotation(AVLTree A)
{
	//A必须要有一个左子结点B，B必须有一个右子结点C
	//将A、B与C做两次单旋，返回新的根结点C

	//将B与C做右单旋，C被返回
	A->Left = SingleRightRotation(A->Left);

	//将A与C做左单旋，C被返回
	return SingleLeftRotation(A);
}

//右左双旋
AVLTree DoubleRightLeftRotation(AVLTree A)
{
	//A必须要有一个右子结点B，B必须有一个左子结点C
	//将A、B与C做两次单旋，返回新的根结点C

	//将B与C做左单旋，C被返回
	A->Right = SingleLeftRotation(A->Right);

	//将A与C做右单旋，C被返回
	return SingleRightRotation(A);
}

//AVL插入
AVLTree Insert(AVLTree A, int X)
{
	//树为空时
	if (!A) {
		A = (AVLTree)malloc(sizeof(AVLNode));
		A->Data = X;
		A->Height = 0;
	}
	else if (X < A->Data) {
		//插入A的左子树
		A->Left = Insert(A->Left, X);
		//如果需要左旋
		if (GetHeight(A->Left) - GetHeight(A->Right) == 2)
			if (X < A->Left->Data)
				A = SingleLeftRotation(A);	//左单旋
			else
				A = DoubleLeftRightRotation(A);	//左右双旋
	}
	else if (X > A->Data) {
		//插入A的右子树
		A->Right = Insert(A->Right, X);
		//如果需要右旋
		if (GetHeight(A->Left) - GetHeight(A->Right) == -2)
			if (X > A->Right->Data)
				A = SingleRightRotation(A);	//右单旋
			else
				A = DoubleRightLeftRotation(A);	//右左双旋
	}
	//else //X==A->Data，无需插入

	//更新树高
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;

	return A;
}