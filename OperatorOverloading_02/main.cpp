#include"main.h"
#include<iostream>
using namespace std;

int main()
{

//����MyArray������[]
#if 0
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

//++i��i++�� ���ز���
#if 0
	stopwatch s1, s2;

	s1 = s2++;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	s1.setzero();
	s2.setzero();

	s1 = ++s2;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s1 << endl;
	return 0;
#endif 

#if 1
	MyComplex c(1.2, 3.4);
	cout << (double)c << endl;  //��� 1.2
	double n = 2 + c;  //�ȼ��� double n = 2 + c. operator double()
	cout << n << endl;  //��� 3.2
#endif // 1


	system("pause");
	return 0;
}


