#include"Stack_Array.h"
#define MinStackSize 100

int IsEmpty(Stack S)
{

}
int IsFull(Stack S);
Stack CreateStack(int MaxElements)
{
	Stack S;
	if (MaxElements < MinStackSize)
		printf("Stack size is too small");

	S = malloc(sizeof(struct StackRecored));
	if (S == NULL)
		printf("Out of space!\n");
	S->Array = malloc(sizeof(ElementType)*MaxElements);
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
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S)
{
	if (IsFull(S))
		printf("Full stack\n");
	else
		S->Array[++S->TopOfStack] = X;
}
ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack];
	printf("Empty stack");
	return 0;
}
void Pop(Stack S)
{
	if (IsEmpty(S))
		printf("Empty stack");
	else
		S->TopOfStack--;
}
ElementType TopAndPop(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	else
		printf("Empty stack");
	return 0;
}