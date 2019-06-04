#include"Stack.h"

bool IsEmpty(Stack S)
{
	return S->next == NULL;
}
Stack CreateStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(ListNode));
	if (S == NULL)
	{
		printf("Out of space!");
		return NULL;
	}
	S->next = NULL;
}
void DisPoseStack(Stack S);
void MakeEmpty(Stack S)
{

}
void Push(Stack S, int X)
{
	ListNode* TmpNode;
	TmpNode = (ListNode*)malloc(sizeof(ListNode));
	if (TmpNode == NULL)
	{
		printf("out of space!");
		return;
	}
	TmpNode->val = X;
	TmpNode->next = S->next;
	S->next = TmpNode;
}
int Pop(Stack S)
{
	ListNode* FirstCell;
	if (IsEmpty(S))
	{
		printf("Empty stack");
		return -1;
	}
	FirstCell = S->next;
	S->next = S->next->next;
	return FirstCell->val;
}