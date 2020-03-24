#include"main.h"
#include<iostream>
using namespace std;

int main()
{

//测试交换两个变量的值 Function Template
#if 0 
		//交换 int 变量的值
		int i1 = 1, i2 = 2;
		MySwap(&i1, &i2);
		cout << i1 << ", " << i2 << endl;

		//交换 float 变量的值
		float f1 = 1.25f, f2 = 2.67f;
		MySwap(&f1, &f2);
		cout << f1 << ", " << f2 << endl;

		//交换 char 变量的值
		char c1 = 'A', c2 = 'B';
		MySwap(c1, c2);
		cout << c1 << ", " << c2 << endl;

		//交换 bool 变量的值
		bool b1 = false, b2 = true;
		MySwap(b1, b2);
		cout << b1 << ", " << b2 << endl;
#endif // 0

//测试求三个数的最大值 Function Template
#if 1
		//求三个整数的最大值
		int im1 = 11, im2 = 22, im3 = 33, iMax = 0;
		iMax = Max(im1, im2, im3);
		cout << "iMax = " << iMax << endl;

		//求三个浮点数的最大值
		float fm1 = 11.11f, fm2 = 22.22f, fm3 = 33.33f, fMax = 0.0f;
		fMax = Max(fm3, fm2, fm1);
		cout << "fMax = " << fMax << endl;

		//求三个长整型数的最大值
		long lm1 = 0, lm2 = 0, lm3 = 0, lMax = 0;
		cin >> lm1 >> lm2 >> lm3;
		lMax = Max(lm1, lm2, lm3);
		cout << "lMax = " << lMax << endl;

#endif // 1


	system("pause");
	return 0;
}
