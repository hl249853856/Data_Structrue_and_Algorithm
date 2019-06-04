#include"List.h"

//���ɿ�����
List MakeEmpty(List L);
//�ж������Ƿ�Ϊ��
int IsEmpty(List L)
{
	return L->Next == NULL;
}
//�жϸ���λ���Ƿ�������ĩβ
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
//��ֵ����
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL&&P->Element != X)
		P = P->Next;

	return P;
}
//��ֵɾ��
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
//���ظ���ֵǰһ�����
Position FindPrevious(ElementType X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL&&P->Element != X)
		P = P->Next;
	
	return P;
}
//����
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
//ɾ������
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
//����ͷ���
Position Header(List L);
//���ص�һ�����
Position First(List L)
{
	return L->Next;
}
//
Position Advance(Position P);

//��λ�ò���
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

//��ӡ����
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