#include"Queue.h"

bool IsEmpty(Queue Q)
{
	return Q->Front == NULL;
}
Queue CreateQueue(int MaxElements)
{
	Queue Q = (Queue)malloc(sizeof(QueueRecord));
	if (Q == NULL)
	{
		printf("out of space");
		return NULL;
	}
	Q->Front = Q->Rear = NULL;
	return Q;
}
void EnQueue(Queue Q, int X)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		printf("out of space");
		return;
	}
	node->val = X;
	node->next = NULL;
	if (Q->Rear == NULL)
	{
		Q->Front = node;
		Q->Rear = node;
	}
	else
	{
		Q->Rear->next = node;
		Q->Rear = node;
	}
}
void DeQueue(Queue Q)
{
	ListNode* node = Q->Front;
	if (Q->Front == NULL)
		return;
	if (Q->Front == Q->Rear)
	{
		Q->Front = NULL;
		Q->Rear = NULL;
		free(node);
	}
	else
	{
		Q->Front = Q->Front->next;
		free(node);
	}
}
int FrontAndDequeue(Queue Q)
{
	ListNode* node = Q->Front;
	if (Q->Front == NULL)
		return;
	if (Q->Front == Q->Rear)
	{
		Q->Front = NULL;
		Q->Rear = NULL;
		return node->val;
	}
	else
	{
		Q->Front = Q->Front->next;
		return node->val;
	}
}