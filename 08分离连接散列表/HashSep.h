#pragma once
#include<stdio.h>
#include<stdlib.h>

#define ElementType int
#define MinTableSize 100

typedef unsigned int Index;
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

struct ListNode
{
	ElementType Element;
	Position Next;
};

typedef struct ListNode *List;

struct HashTbl
{
	int TableSize;
	List *TheLists;
};

//Hashº¯Êý
Index Hash(const ElementType Key, int TableSize);

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);