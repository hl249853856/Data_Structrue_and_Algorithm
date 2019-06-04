#include"Tree.h"

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
SearchTree Find(SearchTree T, int X)
{
	if (T == NULL)
		return NULL;
	if (X < T->val)
		return Find(T->Left, X);
	else if (X > T->val)
		return Find(T->Right, X);
	else
		return T;
}
SearchTree FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	//******易忘点************
	if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
SearchTree FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	while (T->Right != NULL)
		T = T->Right;
	return T;
}
SearchTree Insert(SearchTree T, int X)
{
	if (T == NULL)
	{
		T = (SearchTree)malloc(sizeof(TreeNode));
		if (T == NULL)
		{
			printf("out of space");
			return NULL;
		}
		else
		{
			T->val = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->val)
		T->Left = Insert(T->Left, X);
	else if (X > T->val)
		T->Right = Insert(T->Right, X);

	return T;
}
SearchTree Delete(SearchTree T, int X)
{
	SearchTree Tmp;

	if (T == NULL)
	{
		printf("Element not Found");
		return NULL;
	}

	if (X < T->val)
		T->Left = Insert(T->Left, X);
	else if (X > T->val)
		T->Right = Insert(T->Right, X);
	else 
		//包含两个子节点
		if (T->Left&&T->Right)
		{
			Tmp = FindMin(T->Right);
			T->val = X;
			T->Right = Delete(T->Right, X);
		}
	//一个或两个节点
		else
		{
			Tmp = T;
			if (T->Left == NULL)
				T = T->Right;
			else if (T->Right == NULL)
				T = T->Left;
			free(Tmp);
		}
	return T;
}