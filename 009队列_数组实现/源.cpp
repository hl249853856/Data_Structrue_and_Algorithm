#include"Queue.h"

bool IsEmpty(Queue Q)
{
	return Q->Size == 0;
}
bool IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements)
{
	Queue Q;
	if (MaxElements < MinQueueSize)
	{
		printf("Queue size too small");
		return NULL;
	}
	Q->Array = (int*)malloc(sizeof(int)*MaxElements);
	if (Q->Array == NULL)
	{
		printf("out of space");
		return NULL;
	}
	else
	{
		Q->Capacity = MaxElements;
		Q->Front = 1;
		Q->Rear = 0;
		Q->Size = 0;
	}
	
	
}
void DisposeQueue(Queue Q)
{
	if (Q->Array != NULL)
		free(Q->Array);
	Q->Capacity = 0;
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}
void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}
void EnQueue(Queue Q, int X)
{
	if (IsFull(Q))
	{
		printf("full queue");
		return;
	}
	else
	{
		Q->Size++;
		Q->Rear = ++Q->Rear;
		if (Q->Rear == Q->Capacity)
			Q->Rear = 0;
		Q->Array[++Q->Rear] = X;
	}
}
void DeQueue(Queue Q)
{
	if (IsEmpty(Q))
	{
		printf("empty queue");
		return;
	}
	else
	{
		Q->Size--;
		Q->Front++;
		if (Q->Front == Q->Capacity)
			Q->Front = 0;
	}
}
int FrontAndDequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		printf("empty queue");
		return -1;
	}
	else
	{
		int tmp;
		Q->Size--;
		tmp = Q->Front;
		Q->Front++;
		if (Q->Front == Q->Capacity)
			Q->Front = 0;
		return tmp;
	}
}