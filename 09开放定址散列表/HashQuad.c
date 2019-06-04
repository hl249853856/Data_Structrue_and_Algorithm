#include"HashQuad.h"

//返回相近的素数，此处简略，以7代之
int NextPrime(int TableSize)
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

	H = (struct HashTbl*)malloc(sizeof(struct HashTbl));
	if (H == NULL)
	{
		printf("Table size too small");
		return NULL;
	}

	H->TableSize = NextPrime(TableSize);

	H->TheCells = (Cell*)malloc(sizeof(Cell)*H->TableSize);
	if (H->TheCells = NULL)
	{
		printf("Table size too small");
		return NULL;
	}

	for (int i = 0; i < H->TableSize; i++)
		H->TheCells[i].Info = Empty;
	
	return H;
}
void DestroyTable(HashTable H);

//使用平方探测散列法的Find例程
Position Find(ElementType Key, HashTable H)
{
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info!=Empty&&H->TheCells[CurrentPos].Element!=Key)
	{
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize)
			CurrentPos -= H->TableSize;
	}

	return CurrentPos;
}

//使用平方探测散列表的Insert例程
void Insert(ElementType Key, HashTable H)
{
	Position Pos;

	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate)
	{
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}
}
ElementType Retrieve(Position P, HashTable H);

//再散列
HashTable Rehash(HashTable H)
{
	int OldSize;
	Cell *OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	H = InitializeTable(2 * OldSize);

	for (int i = 0; i < OldSize; i++)
		if (OldCells[i].Info == Legitimate)
			Insert(OldCells[i].Element, H);

	free(OldCells);

	return H;
}