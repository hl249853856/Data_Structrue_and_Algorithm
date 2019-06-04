#include<iostream>


void  PrintArr(int A[], int N)
{
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

void BubbleSort(int A[], int N)
{
	int tmp;
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (A[j] > A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
			}
}


int main()
{
	int s[10] = { 8,1,9,7,2,4,5,6,10,3 };
	std::cout << "ÅÅÐòÇ°£º" << std::endl;
	PrintArr(s, 10);

	BubbleSort(s, 10);

	std::cout << "ÅÅÐòºó£º" << std::endl;
	PrintArr(s, 10);

	return 0;
}
