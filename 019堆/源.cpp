#include<stdio.h>
#include<stdlib.h>
#define MaxData 10000
#define MinData -10000

//����
typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
	int *Elements;
	int Size;
	int Capacity;
};

MaxHeap Create(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(HeapStruct));
	H->Elements = (int*)malloc(sizeof(int)*(MaxSize + 1));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;	//��Ϊ�ڱ�
	return H;
}

bool IsFull(MaxHeap H)
{
	return H->Size == H->Capacity;
}

bool IsEmpty(MaxHeap H)
{
	return H->Size == 0;
}

//����
void Insert(MaxHeap H, int item)
{
	//��Ԫ��item��������H������H->Element[0]�Ѿ�����Ϊ�ڱ�
	int i;
	if (IsFull(H)) {
		printf("��������");
		return;
	}
	i = ++H->Size;
	for (; H->Elements[i / 2] < item; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = item;
}

int DeleteMax(MaxHeap H)
{
	//������H��ȡ����ֵΪ����Ԫ�ز�ɾ��
	int Parent, Child;
	int MaxItem, temp;
	if (IsEmpty(H)) {
		printf("�����ѿ�");
		return H->Elements[0];
	}
	temp = H->Elements[H->Size--];
	for (Parent = 1; Parent * 2 < H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
			Child++;
		if (temp >= H->Elements[Child])
			break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MaxItem;
}

//��������
void PercDown(MaxHeap H, int p)
{
	//����
	int Parent, Child;
	int X;

	X = H->Elements[p];//ȡ��������ŵ�ֵ
	for (Parent = p; Parent * 2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && H->Elements[Child] < H->Elements[Child + 1])
			Child++;
		if (X >= H->Elements[Child])
			break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = X;
}

void BuildMaxHeap(MaxHeap H)
{
	//����H->Elements[]�е�Ԫ�أ�ʹ�������ѵ�������
	//�����������H->Size��Ԫ���Ѿ�����H->Element��
	int i;
	for (i = H->Size / 2; i > 0; i--)
		PercDown(H, i);
}





//��С��
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
	int *Elements;
	int Size;
	int Capacity;
};

MinHeap Create(int MaxSize)
{
	MinHeap H = (MinHeap)malloc(sizeof(HeapStruct));
	H->Elements = (int*)malloc(sizeof(int)*(MaxSize + 1));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MinData;	//��Ϊ�ڱ�
	return H;
}

bool IsFull(MinHeap H)
{
	return H->Size == H->Capacity;
}

bool IsEmpty(MinHeap H)
{
	return H->Size == 0;
}

//����
void Insert(MinHeap H, int item)
{
	//��Ԫ��item��������H������H->Element[0]�Ѿ�����Ϊ�ڱ�
	int i;
	if (IsFull(H)) {
		printf("��������");
		return;
	}
	i = ++H->Size;
	for (; H->Elements[i / 2] > item; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = item;
}

int DeleteMax(MinHeap H)
{
	//������H��ȡ����ֵΪ����Ԫ�ز�ɾ��
	int Parent, Child;
	int MinItem, temp;
	if (IsEmpty(H)) {
		printf("��С���ѿ�");
		return H->Elements[0];
	}
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

//������С��
void PercDown(MinHeap H, int p)
{
	//����
	int Parent, Child;
	int X;

	X = H->Elements[p];//ȡ��������ŵ�ֵ
	for (Parent = p; Parent * 2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && H->Elements[Child] > H->Elements[Child + 1])
			Child++;
		if (X <= H->Elements[Child])
			break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = X;
}

void BuildMaxHeap(MinHeap H)
{
	//����H->Elements[]�е�Ԫ�أ�ʹ�������ѵ�������
	//�����������H->Size��Ԫ���Ѿ�����H->Element��
	int i;
	for (i = H->Size / 2; i > 0; i--)
		PercDown(H, i);
}