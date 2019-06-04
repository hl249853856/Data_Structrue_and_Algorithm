#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MinTableSize 100

unsigned int Hash(const int val, int TableSize)
{
	return val%TableSize;
}

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

enum KindOfEntry{Legitimate,Empty,Deleted};
struct HashEntry {
	int val;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl {
	int TableSize;
	Cell *TheCells;
};

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(HashTable H, int Key);
void Insert(HashTable H, int Key);
HashTable Rehash(HashTable H);