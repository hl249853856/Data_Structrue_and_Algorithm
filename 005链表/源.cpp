#include"_List.h"

List MakeEmpty(List L)
{
	ListNode* P;
	ListNode* Tmp;
	P = L->next;
	while (P)
	{
		Tmp = P->next;
		free(P);
		P = Tmp;
	}
	return L;
}
bool IsEmpty(List L)
{
	return L->next == NULL;
}
bool IsLast(List L, ListNode* P)
{
	return P->next == NULL;
}
ListNode* Find(List L, int X)
{
	ListNode* P;
	P = L->next;
	while (P != NULL&&P->val != X)
		P = P->next;

	return P;
}
void Delete(List L, int X)
{
	ListNode* P;
	ListNode* Tmp;
	P = FindPrevious(L, X);
	if (!IsLast(L, P))
	{
		Tmp = P->next;
		P->next = P->next->next;
		free(Tmp);
		Tmp = NULL;
	}
}
ListNode* FindPrevious(List L, int X)
{
	ListNode* P;
	P = L->next;
	while (P->next != NULL&&P->next->val != X)
		P = P->next;
	return P;
}
void Insert(List L, ListNode* P, int X)
{
	ListNode* TmpNode;
	TmpNode = (ListNode*)malloc(sizeof(ListNode));
	if (TmpNode == NULL)
	{
		printf("out of space!");
		return;
	}
	TmpNode->val = X;
	TmpNode->next = P->next;
	P->next = TmpNode;
}
//void DeleteList(List L);
//ListNode* Header(List L);
ListNode* First(List L)
{
	return L->next;
}
//ListNode* Advance(ListNode* P);
//int Retrieve(ListNode* P);