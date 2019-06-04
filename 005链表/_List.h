#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode;
typedef ListNode* List;
struct ListNode{
	int val;
	ListNode* next;
};

List MakeEmpty(List L);
bool IsEmpty(List L);
bool IsLast(List L, ListNode* P);
ListNode* Find(List L, int X);
void Delete(List L, int X);
ListNode* FindPrevious(List L, int X);
void Insert(List L, ListNode* P, int X);
void DeleteList(List L);
ListNode* Header(List L);
ListNode* First(List L);
ListNode* Advance(ListNode* P);
int Retrieve(ListNode* P);