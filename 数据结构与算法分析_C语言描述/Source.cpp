#include<iostream>
#include<string>
using namespace std;

////Fibonacci数列
////递归调用
//long long fibonacci1(int n)
//{
//	if (n <= 1)
//		return 1;
//	return fibonacci1(n - 1) + fibonacci1(n - 2);
//}
//
////尾递归
//long long fibonacci2(long long n)
//{
//	int ac1 = 1, int ac2 = 1;
//	if (n <= 1)
//		return ac2;
//	return fibonacci2(n - 1, ac2, ac1 + ac2);
//}
//
//int main()
//{
//	cout << "普通递归 " << fibonacci1(10) << endl;
//	cout << "尾递归   " << fibonacci2(100) << endl;
//
//	return 0;
//}


//int A = 11;
//int main()
//{
//
//	//int a = 0;
//	//int b = { 0 };
//	//int c(0);
//	//int d{ 0 };
//	//int ele;
//	//string s;
//	//int _;
//
//	//cout << a << endl;
//	//cout << b << endl;
//	//cout << c << endl;
//	//cout << d << endl;
//	//cout << A << endl;
//	//cout << endl;
//	//cout << s << endl;
//
//	int b = 0;
//	cout << A << " " << b << endl;
//	int A = 1;
//	cout << A << " " << b << endl;
//	cout << endl;
//	cout << ::A << " " << b << endl;
//	cout << endl;
//
//	return 0;
//}

//int A = 99;
//int main()
//{
//	int i = 100;
//	int j = i;
//	cout << i << endl;
//
//	return 0;
//}


void  PrintArr(int A[], int N)
{
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}


int cmp(const void *a,const void *b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	return *pa - *pb;
}

int main()
{
	int s[10] = { 8,1,9,7,2,4,5,6,10,3 };
	std::cout << "排序前：" << std::endl;
	PrintArr(s, 10);

	qsort(s, 10,sizeof(int),cmp);

	std::cout << "排序后：" << std::endl;
	PrintArr(s, 10);

	return 0;
}