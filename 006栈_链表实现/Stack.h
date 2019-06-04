#pragma once
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	ListNode* next;
};

typedef ListNode* Stack;

bool IsEmpty(Stack S);
Stack CreateStack();
void DisPoseStack(Stack S);
void MakeEmpty(Stack S);
void Push(Stack S, int X);
int Pop(Stack S);