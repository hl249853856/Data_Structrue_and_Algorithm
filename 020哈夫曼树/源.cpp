#include<stdio.h>
#include<stdlib.h>
#define MinData -10000

//最小堆
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
	int *Elements;
	int Size;
	int Capacity;
};

//最小堆
MinHeap Create(int MaxSize)
{
	MinHeap H = (MinHeap)malloc(sizeof(HeapStruct));
	H->Elements = (int*)malloc(sizeof(int)*(MaxSize + 1));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MinData;	//作为哨兵
	return H;
}


int IsFull(MinHeap H)
{
	return H->Size == H->Capacity;
}

int IsEmpty(MinHeap H)
{
	return H->Size == 0;
}

void Insert(MinHeap H, int item)
{
	//将元素item插入最大堆H，其中H->Element[0]已经定义为哨兵
	int i;
	if (IsFull(H)) {
		printf("最小堆已满");
		return;
	}
	i = ++H->Size;
	for (; H->Elements[i / 2] > item; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = item;
}

int DeleteMin(MinHeap H)
{
	//从最小堆H中取出键值为最小的元素并删除
	int Parent, Child;
	int MinItem, temp;
	if (IsEmpty(H)) {
		printf("最小堆已空");
		return H->Elements[0];
	}
	MinItem = H->Elements[1];	//取出根结点最小值
	temp = H->Elements[H->Size--];
	for (Parent = 1; Parent * 2 < H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] > H->Elements[Child + 1]))
			Child++;
		if (temp <= H->Elements[Child])
			break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MinItem;
}

//----------建造最小堆--------------
void PercDown(MinHeap H, int p)
{
	//下滤
	int Parent, Child;
	int X;

	X = H->Elements[p];//取出根结点存放的值
	for (Parent = p; Parent * 2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if (Child != H->Size&&H->Elements[Child] > H->Elements[Child + 1])
			Child++;
		if (X <= H->Elements[Child])
			break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = X;
}

void BuildMinHeap(MinHeap H)
{
	//调整H->Element[]中的元素，使满足最大堆的有序性
	//这里假设所有H->Size个元素已经存在H->Element中
	int i;
	for (i = H->Size / 2; i > 0; i--)
		PercDown(H, i);
}

typedef struct TreeNode *HuffmanTree;
struct TreeNode {
	int Weight;
	HuffmanTree Left, Right;
};

HuffmanTree Huffman(MinHeap H)
{
	//假设H->Size个权值已经存在H->Element[]->Weight里
	int i;
	HuffmanTree T;
	BuildMinHeap(H);//将H->Elements[]按权值调整为最小堆
	for (i = 1; i < H->Size; i++)
	{
		//做H->Size-1次合并
		T = (HuffmanTree)malloc(sizeof(TreeNode));//建立新结点
		T->Left = DeleteMin(H);
	}
}