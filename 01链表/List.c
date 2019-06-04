#include"List.h"

//生成空链表
List MakeEmpty(List L);
//判断链表是否为空
int IsEmpty(List L)
{
	return L->Next == NULL;
}
//判断给定位置是否是链表末尾
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
//按值查找
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL&&P->Element != X)
		P = P->Next;

	return P;
}
//按值删除
void Delete(ElementType X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}
//返回给定值前一个结点
Position FindPrevious(ElementType X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL&&P->Element != X)
		P = P->Next;
	
	return P;
}
//插入
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
	{
		printf("Out of space!");
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
//删除链表
void DeleteList(List L)
{
	Position P, Tmp;

	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}
//返回头结点
Position Header(List L);
//返回第一个结点
Position First(List L)
{
	return L->Next;
}
//
Position Advance(Position P);

//按位置插入
void InsertByPos(ElementType X, List L, int N)
{
	Position TempCell;
	List pCurrent;
	pCurrent = L->Next;
	TempCell = malloc(sizeof(struct Node));
	if (TempCell == NULL)
	{
		printf("Out of space!");
	}
	TempCell->Element = X;
	for (int i = 0; i < N; i++)
	{
		pCurrent = pCurrent->Next;
	}
	TempCell = pCurrent->Next;
	pCurrent->Next = TempCell;
}

//打印链表
void PrintList(List L)
{
	if (IsEmpty(L))
		return;
	List pCurrent=L->Next;
	while (pCurrent != NULL)
	{
		printf("%d  ", pCurrent->Element);
		pCurrent = pCurrent->Next;
	}
	printf("\n");
}