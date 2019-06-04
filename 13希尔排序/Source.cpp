#include<iostream>

void  PrintArr(int A[], int N)
{
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

//Ï£¶ûÅÅÐò
void ShellSort(int A[], int N)
{
	int i, j, Increment;
	int tmp;

	for(Increment=N/2;Increment>0;Increment/=2)
		for (i = Increment; i < N; i++)
		{
			tmp = A[i];
			for (j = i; j >= Increment; j -= Increment)
				if (tmp < A[j - Increment])
					A[j] = A[j - Increment];
				else
					break;
			A[j] = tmp;
		}
}




int main()
{
	int s[10] = { 8,1,9,7,2,4,5,6,10,3 };
	std::cout << "ÅÅÐòÇ°£º" << std::endl;
	PrintArr(s, 10);

	ShellSort(s, 10);

	std::cout << "ÅÅÐòºó£º" << std::endl;
	PrintArr(s, 10);

	return 0;
}