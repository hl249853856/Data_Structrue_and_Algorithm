#include<iostream>
using namespace std;

//ŷ������㷨���������
unsigned int Gcd(unsigned int M, unsigned int N)
{
	unsigned Rem;
	while (N > 0)
	{
		Rem = M%N;
		M = N;
		N = Rem;
	}
	return M;
}

int main()
{
	return 0;
}