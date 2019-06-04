#include<iostream>
//分治法
int Max3(int a, int b, int c)
{
	if (a >= b&&a >= c)
		return a;
	if (b >= a&&b >= c)
		return b;
	if (c >= a&&c >= b)
		return c;

}

static int MaxSubSum(const int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int Center, i;

	if (Left == Right)
		if (A[Left] > 0)
			return A[Left];
		else
			return 0;

	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center + 1, Right);

	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = Center; i >= Left; i--)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (i = Center + 1; i <= Right; i++)
	{
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubSequenceSum1(const int A[], int N)
{
	return MaxSubSum(A, 0, N - 1);
}

//线性算法
int MaxSubSequenceSum2(const int A[], int N)
{
	int ThisSum, MaxSum, i;
	ThisSum = MaxSum = 0;

	for (i = 0; i < N; i++)
	{
		ThisSum += A[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}

int main()
{

	return 0;
}