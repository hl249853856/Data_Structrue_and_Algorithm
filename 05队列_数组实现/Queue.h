#pragma once
#include<stdio.h>
#include<stdlib.h>

#define ElementType int
#define MaxElements 100
#define MinQueueSize 5

struct QueueRecored;
typedef struct QueueRecored *Queue;

struct QueueRecored
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);