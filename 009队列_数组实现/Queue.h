#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MinQueueSize (5)

typedef struct QueueRecord *Queue;
struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int *Array;
};

bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void EnQueue(Queue Q, int X);
void DeQueue(Queue Q);
int FrontAndDequeue(Queue Q);