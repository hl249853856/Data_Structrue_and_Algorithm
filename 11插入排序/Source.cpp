#include<iostream>

void  PrintArr(int A[], int N)
{
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

void InsertSort(int A[], int N)
{
	int tmp;
	for(int i=1;i<N;i++)
		if (A[i] < A[i - 1])
		{
			tmp = A[i];
			int j;
			for (j = i ; j >= 0 && tmp < A[j-1]; j--)
				A[j] = A[j-1];
			A[j] = tmp;
		}
}

int main()
{
	int s[10] = { 8,1,9,7,2,4,5,6,10,3 };
	std::cout << "ÅÅÐòÇ°£º" << std::endl;
	PrintArr(s, 10);

	InsertSort(s, 10);

	std::cout << "ÅÅÐòºó£º" << std::endl;
	PrintArr(s, 10);

	return 0;
}