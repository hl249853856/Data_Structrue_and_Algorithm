#include<iostream>
#define Cutoff (3)

void  PrintArr(int A[], int N)
{
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

//²åÈëÅÅÐò
void InsertSort(int A[], int N)
{
	int tmp;
	for (int i = 1; i<N; i++)
		if (A[i] < A[i - 1])
		{
			tmp = A[i];
			int j;
			for (j = i; j >= 0 && tmp < A[j - 1]; j--)
				A[j] = A[j - 1];
			A[j] = tmp;
		}
}

void Swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int Median3(int A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;

	if (A[Left] > A[Center])
		Swap(A[Left], A[Center]);
	if (A[Left] > A[Right])
		Swap(A[Left], A[Right]);
	if (A[Center] > A[Right])
		Swap(A[Center], A[Right]);

	Swap(A[Center], A[Right - 1]);
	return A[Right - 1];
}

void QSort(int A[], int Left,int Right)
{
	if (Cutoff <= Right - Left) {
		int i, j, Pivot;
		Pivot = Median3(A, Left, Right);
		i = Left; j = Right - 1;
		for (;;) {
			while (A[++i] < Pivot) {}
			while (A[--j] < Pivot) {}
			if (i < j)
				Swap(A[i], A[j]);
			else
				break;
		}
		Swap(A[i], A[Right - 1]);

		QSort(A, Left, i - 1);
		QSort(A, i + 1, Right);
	}
	else
		InsertSort(A + Left, Right - Left + 1);
}

void QuickSort(int A[], int N)
{
	QSort(A, 0, N - 1);
}


int main()
{
	int s[10] = { 8,1,9,7,2,4,5,6,10,3 };
	std::cout << "ÅÅÐòÇ°£º" << std::endl;
	PrintArr(s, 10);

	QuickSort(s, 10);

	std::cout << "ÅÅÐòºó£º" << std::endl;
	PrintArr(s, 10);

	return 0;
}