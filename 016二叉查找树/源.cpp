#include<stdio.h>
#include<stdlib.h>

struct TreeNode;
typedef struct TreeNode* BinTree;
typedef BinTree Position;

//定义树结点
struct TreeNode {
	int Data;
	BinTree Left;
	BinTree Right;
	TreeNode(int X) :Data(X), Left(NULL), Right(NULL) {}
};


//递归查找
Position Find(BinTree BT, int X)
{
	if (!BT) return NULL;
	if (X < BT->Data)
		return Find(BT->Left, X);
	else if (X > BT->Data)
		return Find(BT->Right, X);
	return BT;
}

//迭代查找
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

//递归查找最小元素
Position FindMin(BinTree BT)
{
	if (!BT) return NULL;
	if (BT->Left == NULL)
		return BT;
	else
		return FindMin(BT->Left);
}

//查找最大元素
Position FindMax(BinTree BT)
{
	if (!BT) return NULL;
	while (BT->Right)
		BT = BT->Right;
	return BT;
}

//插入,返回根结点
BinTree Insert(BinTree BT, int X)
{
	if (!BT)
		BT = new TreeNode(X);
	else if (X < BT->Data)
		BT->Left = Insert(BT->Left, X);
	else if (X > BT->Data)
		BT->Right = Insert(BT->Right, X);
	//else X已存在，什么都不做

	return BT;
}

//删除
//要删除的结点有左右两颗子树时，用另一个结点替代被删除结点
//使用右子树的最小元素或左子树的最大元素
BinTree Delete(BinTree BT, int X)
{
	Position Tmp;
	if (!BT)
		printf("树为空");
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
			if (!BT->Left)	//左子树为空
				BT = BT->Right;
			if (!BT->Right)	//右子树为空
				BT = BT->Left;
		}
	}
	return BT;
}