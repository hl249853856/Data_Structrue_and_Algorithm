#include<iostream>
#define LeftChild(i) (2*(i)+1)

void  PrintArr(int A[], int N)
{
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}



//¹é²¢ÅÅÐò
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	while (Lpos <= LeftEnd&&Rpos <= RightEnd)
		if (A[Lpos] <= A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];

	while (Lpos <= LeftEnd)
		TmpArray[TmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];

	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpArray[RightEnd];
}
void MSort(int A[], int TmpArray[], int Left, int Right)
{
	int Center;

	if (Left < Right)
	{
		Center = (Left + Right) / 2;
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center+1, Right);
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}
void MergeSort(int A[], int N)
{
	int *TmpArray;

	TmpArray = (int*)malloc(N * sizeof(int));
	if (TmpArray != NULL)
	{
		MSort(A, TmpArray, 0, N - 1);
		free(TmpArray);
	}
	else
	{
		std::cout << "No space for tmp array!" << std::endl;
		return;
	}
}


int main()
{
	int s[10] = { 8,1,9,7,2,4,5,6,10,3 };
	std::cout << "ÅÅÐòÇ°£º" << std::endl;
	PrintArr(s, 10);

	MergeSort(s, 10);

	std::cout << "ÅÅÐòºó£º" << std::endl;
	PrintArr(s, 10);

	return 0;
}