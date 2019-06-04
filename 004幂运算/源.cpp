#include<iostream>
using namespace std;

//ÃİÔËËã
long int Pow(long int x, unsigned int N)
{
	if (N == 0)
		return 1;
	if (N == 1)
		return x;
	if (N % 2 == 0)
		return Pow(x*x, N / 2);
	else
		return Pow(x*x, N / 2)*x;
}

int main()
{
	return 0;
}