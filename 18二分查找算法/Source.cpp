#include<iostream>
using namespace std;

int BinarySearch(int A[], int N, int K)
{
	int Left, Right, Mid;
	int NotFound = -1;

	Left = 0;
	Right = N - 1;
	while (Left<=Right)
	{
		Mid = (Left + Right) / 2;
		if (K < A[Mid])
			Right = Mid - 1;
		else if (K > A[Mid])
			Left = Mid + 1;
		else
			return Mid;
	}
	return NotFound;
}

int main()
{
	int A[10] = { 1,3,10,15,23,33,43,44,64,76 };
	cout << BinarySearch(A, 10, 44) << endl;

	return 0;
}