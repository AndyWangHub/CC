#include"main.h"
#include<iostream>
using namespace std;

int main()
{

//²âÊÔMyArrayÀàÖØÔØ[]
#if 1
	int n = 0;
	cin >> n;
	MyArray A(n);
	
	for (size_t i = 0; i < n; i++)
	{
		A[i] = i * 2;
	}
	A.display();

	const MyArray B(n);
	cout << B[n - 1] << endl;

#endif 
	system("pause");
	return 0;
}