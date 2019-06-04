#include<iostream>
#define NotFound -1
using namespace std;

//∂‘∑÷≤È’“
int BinarySearch(const int A[], int N, int X)
{
	int Left = 0, Right = N - 1;
	int Mid;
	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;
		if (X < A[Mid])
			Right = Mid - 1;
		else if (X > A[Mid])
			Left = Mid + 1;
		else
			return A[Mid];
	}
	
	return NotFound;
}

int main()
{
	return 0;
}