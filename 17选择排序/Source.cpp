#include<iostream>


void  PrintArr(int A[], int N)
{
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//Ñ¡ÔñÅÅÐò
void SelectSort(int A[], int N)
{
	int i, j, min;
	for (i = 0; i < N-1; i++)
	{
		min = i;
		for (j = i; j < N; j++)
			if (A[j] < A[min])
				min = j;
		Swap(&A[i], &A[min]);
	}
}

int main()
{
	int s[10] = { 8,1,9,7,2,4,5,6,10,3 };
	std::cout << "ÅÅÐòÇ°£º" << std::endl;
	PrintArr(s, 10);

	SelectSort(s, 10);

	std::cout << "ÅÅÐòºó£º" << std::endl;
	PrintArr(s, 10);

	return 0;
}