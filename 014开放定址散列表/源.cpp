#include"HashQuad.h"

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	
	if (TableSize < MinTableSize)
	{
		printf("Table size too small");
		return NULL;
	}

	H = (HashTable)malloc(sizeof(HashTbl));
	if (H == NULL)
	{
		printf("out of space");
		return NULL;
	}

	H->TableSize = TableSize;

	H->TheCells = (HashEntry*)malloc(sizeof(HashEntry));
	if (H == NULL)
	{
		printf("out of space");
		return NULL;
	}

	for (int i = 0; i < H->TableSize; i++)
		H->TheCells[i].Info = Empty;

	return H;
}
void DestroyTable(HashTable H);
Position Find(HashTable H, int Key)
{
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty&&
		H->TheCells[CurrentPos].val != Key)
	{
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize)
			CurrentPos -= H->TableSize;
	}
	return CurrentPos;
}
void Insert(HashTable H, int Key)
{
	Position Pos;

	Pos = Find(H, Key);
	if (H->TheCells[Pos].Info != Legitimate)
	{
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].val = Key;
	}
}
HashTable Rehash(HashTable H)
{
	int  OldSize;
	Cell *OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	H = InitializeTable(2 * OldSize);

	for (int i = 0; i < OldSize; i++)
		if (OldCells[i].Info == Legitimate)
			Insert(H, OldCells[i].val);
	free(OldCells);
	return H;
}