#include"Stack.h"

bool IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}
bool IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity;
}
Stack CreateStack(int MaxElements)
{
	Stack S;
	if (MaxElements < MinStackSize)
	{
		printf("Stack size is too small!");
		return NULL;
	}
	S = (Stack)malloc(sizeof(StackRecord));
	if (S == NULL)
	{
		printf("out of space!");
		return NULL;
	}
	S->Array = (int*)malloc(sizeof(int)*MaxElements);
	if (S->Array == NULL)
	{
		printf("out of space!");
		return NULL;
	}
	S->Capacity = MaxElements;
	MakeEmpty(S);
	return S;
}
void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}
void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}
void Push(Stack S, int X)
{
	if (IsFull(S))
	{
		printf("Full Stack");
		return;
	}
	else
		S->Array[++S->TopOfStack] = X;
}
int Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack];
	printf("Empty Stack");
	return 0;
}
void Pop(Stack S)
{
	if (!IsEmpty(S))
		S->TopOfStack--;
	else
		printf("Empty Stack");
}
int TopAndPop(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	printf("Empty Stack");
	return 0;
}