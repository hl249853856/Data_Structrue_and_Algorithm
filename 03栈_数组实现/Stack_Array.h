#pragma once
#include<stdio.h>
#include<stdlib.h>
#define ElementType int

//��Ҫ��ǰ����һ������Ĵ�С
struct StackRecored;
typedef struct StackRecored *Stack;

struct StackRecored {
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);