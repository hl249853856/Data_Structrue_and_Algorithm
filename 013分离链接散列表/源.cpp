#include"HashSep.h"

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	if (TableSize < MinTableSize)
	{
		printf("Table size too small");
		return NULL;
	}

	H = (HashTable)malloc(sizeof(HashTable));
	if (H == NULL)
	{
		printf("out of space");
		return NULL;
	}

	H->TableSize = TableSize;//设置表的大小
	H->TheLists = (List*)malloc(sizeof(List)*H->TableSize);
	if (H == NULL)
	{
		printf("out of space");
		return NULL;
	}

	for (i = 0; i < H->TableSize; i++)
	{
		//使用了表头
		H->TheLists[i] = (List)malloc(sizeof(ListNode));
		if (H->TheLists[i] == NULL)
		{
			printf("out of space");
			return NULL;
		}
		else
			H->TheLists[i]->next = NULL;
	}
	return H;
}
void DestroyTable(HashTable H);
ListNode* Find(HashTable H, int Key)
{
	ListNode* P;
	List L;

	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->next;
	while (P != NULL&&P->val != Key)
		P = P->next;
	return P;
}
void Insert(HashTable H, int Key)
{
	ListNode* Pos;
	ListNode* NewCell;
	List L;

	Pos = Find(H, Key);
	if (Pos == NULL)
	{
		NewCell = (ListNode*)malloc(sizeof(ListNode));
		if(NewCell==NULL)
		{
			printf("out of space");
			return;
		}
		else
		{
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->next = L->next;
			NewCell->val = Key;
			L->next = NewCell;
		}
	}
}

void Delete(HashTable H, int Key)
{
	List L;
	ListNode* Tmp;
	ListNode* P;

	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L;
	while (P->next != NULL&&P->next->val != Key)
		P = P->next;
	if (P->next == NULL)
		return;
	Tmp = P->next;
	P->next = P->next->next;
	free(Tmp);
	Tmp = NULL;
}