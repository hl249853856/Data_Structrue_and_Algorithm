#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode* List;
struct ListNode
{
	int val;
	ListNode* next;
};

typedef struct QueueRecord *Queue;
struct QueueRecord
{
	ListNode* Front;
	ListNode* Rear;
};

bool IsEmpty(Queue Q);
Queue CreateQueue();
void EnQueue(Queue Q, int X);
void DeQueue(Queue Q);
int FrontAndDequeue(Queue Q);