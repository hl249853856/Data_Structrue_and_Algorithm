#include<stdio.h>
#include<stdlib.h>
#define MinData -10000

//��С��
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
	int *Elements;
	int Size;
	int Capacity;
};

//��С��
MinHeap Create(int MaxSize)
{
	MinHeap H = (MinHeap)malloc(sizeof(HeapStruct));
	H->Elements = (int*)malloc(sizeof(int)*(MaxSize + 1));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MinData;	//��Ϊ�ڱ�
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
	//��Ԫ��item��������H������H->Element[0]�Ѿ�����Ϊ�ڱ�
	int i;
	if (IsFull(H)) {
		printf("��С������");
		return;
	}
	i = ++H->Size;
	for (; H->Elements[i / 2] > item; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = item;
}

int DeleteMin(MinHeap H)
{
	//����С��H��ȡ����ֵΪ��С��Ԫ�ز�ɾ��
	int Parent, Child;
	int MinItem, temp;
	if (IsEmpty(H)) {
		printf("��С���ѿ�");
		return H->Elements[0];
	}
	MinItem = H->Elements[1];	//ȡ���������Сֵ
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

//----------������С��--------------
void PercDown(MinHeap H, int p)
{
	//����
	int Parent, Child;
	int X;

	X = H->Elements[p];//ȡ��������ŵ�ֵ
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
	//����H->Element[]�е�Ԫ�أ�ʹ�������ѵ�������
	//�����������H->Size��Ԫ���Ѿ�����H->Element��
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
	//����H->Size��Ȩֵ�Ѿ�����H->Element[]->Weight��
	int i;
	HuffmanTree T;
	BuildMinHeap(H);//��H->Elements[]��Ȩֵ����Ϊ��С��
	for (i = 1; i < H->Size; i++)
	{
		//��H->Size-1�κϲ�
		T = (HuffmanTree)malloc(sizeof(TreeNode));//�����½��
		T->Left = DeleteMin(H);
	}
}