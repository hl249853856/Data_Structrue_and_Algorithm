#include"Queue.h"


int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}
int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements)
{

}
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
	if (++Value == Q->Capacity)
		Value = 0;
	return Value;
}

void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
		printf("Full queue");
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}


ElementType Front(Queue Q)
{
	return Q->Array[Q->Front];
}
void Dequeue(Queue Q)
{
	Q->Size--;
	Q->Front = Succ(Q->Front, Q);
	
}
ElementType FrontAndDequeue(Queue Q)
{
	ElementType Tmp = Q->Array[Q->Front];
	Q->Size--;
	Q->Front = Succ(Q->Front, Q);
	return Tmp;
}