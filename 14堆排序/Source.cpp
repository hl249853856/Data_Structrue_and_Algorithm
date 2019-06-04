#include<iostream>
#define LeftChild(i) (2*(i)+1)

void  PrintArr(int A[], int N)
{
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

//¶ÑÅÅÐò
void Swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void PercDown(int A[], int i, int N)
{
	int Child;
	int Tmp;

	for (Tmp = A[i]; LeftChild(i) < N; i = Child)
	{
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child + 1] > A[Child])
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;
}
void HeapSort(int A[], int N)
{
	int i;

	for (i = N / 2; i >= 0; i--)
		PercDown(A, i, N);
	for (i = N - 1; i > 0; i--)
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}


int main()
{
	int s[10] = { 8,1,9,7,2,4,5,6,10,3 };
	std::cout << "ÅÅÐòÇ°£º" << std::endl;
	PrintArr(s, 10);

	HeapSort(s, 10);

	std::cout << "ÅÅÐòºó£º" << std::endl;
	PrintArr(s, 10);

	return 0;
}