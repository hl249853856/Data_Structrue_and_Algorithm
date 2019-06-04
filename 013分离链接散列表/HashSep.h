#ifndef HashSep_H
#define HashSep_H

#include<stdio.h>
#include<stdlib.h>
#define MinTableSize 100
struct ListNode;
typedef struct ListNode* List;
struct ListNode {
	int val;
	ListNode* next;
};

struct HashTbl;
typedef struct HashTbl* HashTable;
struct HashTbl {
	int TableSize;
	List *TheLists;
};

int Hash(const int val, int TableSize)
{
	return val%TableSize;
}

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
ListNode* Find(HashTable H, int Key);
void Insert(HashTable H, int Key);
void Delete(HashTable H, int Key);

#endif // !HashSep
