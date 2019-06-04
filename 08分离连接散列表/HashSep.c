#include"HashSep.h"


//返回一个素数，此处简略。以7代之
int NextPrime(int N)
{
	return 7;
}

//Hash函数
Index Hash(const ElementType Key, int TableSize)
{
	return Key%TableSize;
}

HashTable InitializeTable(int TableSize)
{
	HashTable H;

	if (TableSize < MinTableSize)
	{
		printf("Table size too small");
		return NULL;
	}

	H = malloc(sizeof(struct HashTbl));
	if (H == NULL)
	{
		printf("Out of space");
		return NULL;
	}
	H->TableSize = NextPrime(TableSize);

	H->TheLists = malloc(sizeof(List)*H->TableSize);
	if (H->TheLists == NULL)
	{
		printf("Out of space");
		return NULL;
	}

	//为每个链表建立头结点
	for (int i = 0; i < TableSize; i++)
	{
		H->TheLists[i] = malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
		{
			printf("Out of space");
			return NULL;
		}
		else
			H->TheLists[i]->Next = NULL;
	}

	return H;
}
void DestroyTable(HashTable H)
{

}
Position Find(ElementType Key, HashTable H)
{
	Position P;
	List L;

	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;

	while (P != NULL&&P->Element != Key)
		P = P->Next;

	return P;
}
void Insert(ElementType Key, HashTable H)
{
	Position Pos, NewCell;
	List L;

	Pos = Find(Key, H);
	if (Pos == NULL)
	{
		NewCell = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
		{
			printf("Out of space");
			return;
		}
		else
		{
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}
ElementType Retrieve(Position P);