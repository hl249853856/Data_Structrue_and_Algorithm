#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MinStackSize 5
#define EmptyTOS (-1)
struct StackRecord {
	int Capacity;
	int TopOfStack;
	int *Array;
};

typedef struct StackRecord* Stack;

bool IsEmpty(Stack S);
bool IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(Stack S, int X);
int Top(Stack S);
void Pop(Stack S);
int TopAndPop(Stack S);
