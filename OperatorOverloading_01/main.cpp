#include<iostream>
#include "main.h"
using namespace std;

int main()
{
//≤‚ ‘Complex¿‡
#if 1
    MyComplex c1(25, 35);
    MyComplex c2(10, 20);
    MyComplex c3(1, 2);
    MyComplex c4(4, 9);
    MyComplex c5(34, 6);
    MyComplex c6(80, 90);

    MyComplex c7 = c1 + c2;
    MyComplex c8 = c1 - c2;
    MyComplex c9 = c1 * c2;
    MyComplex c10 = c1 / c2;
    cout << "c7 = " << c7.real() << " + " << c7.imag() << "i" << endl;
    cout << "c8 = " << c8.real() << " + " << c8.imag() << "i" << endl;
    cout << "c9 = " << c9.real() << " + " << c9.imag() << "i" << endl;
    cout << "c10 = " << c10.real() << " + " << c10.imag() << "i" << endl;

    c3 += c1;
    c4 -= c2;
    c5 *= c2;
    c6 /= c2;
    cout << "c3 = " << c3.real() << " + " << c3.imag() << "i" << endl;
    cout << "c4 = " << c4.real() << " + " << c4.imag() << "i" << endl;
//    cout << "c5 = " << c5.real() << " + " << c5.imag() << "i" << endl;
//    cout << "c6 = " << c6.real() << " + " << c6.imag() << "i" << endl;
    cout << "c5 = " << c5 << endl;
    cout << "c6 = " << c6 << endl;

    if (c1 == c2) {
        cout << "c1 == c2" << endl;
    }
    if (c1 != c2) {
        cout << "c1 != c2" << endl;
    }

    MyComplex c11, c12;
    cin >> c11 >> c12;
    cout << "c11 = " << c11 << endl;
    cout << "c12 = " << c12 << endl;

#endif

	system("pause");
	return 0;
}


