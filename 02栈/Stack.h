#pragma once
#include<stdio.h>
#include<stdlib.h>
#define ElementType int

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

//是否为空栈
int IsEmpty(Stack S);
//新建栈
Stack CreateStack();
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);