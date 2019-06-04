#include<iostream>
using namespace std;

//欧几里得算法求最大公因数
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