#pragma once
#include<iostream>
#include<string>
#include<exception>
using namespace std;

class Base{};
class Derived:public Base{};

void two()
{
	try
	{
		throw Derived();//抛出自己的异常类型，实际上是创建一个Derived类型的匿名对象
		cout << "This statement will not be executed." << endl;
	}
    catch (int) 
    {
        cout << "Exception type: int" << endl;
    }
    catch (char*) 
    {
        cout << "Exception type: cahr *" << endl;
    }
    catch (Base) 
    {  //匹配成功（向上转型）
        cout << "Exception type: Base" << endl;
    }
    catch (Derived) 
    {
        cout << "Exception type: Derived" << endl;
    }



    int nums[] = { 1, 2, 3 };
    try {
        throw nums;
        cout << "This statement will not be executed." << endl;
    }
    catch (const int*) {
        cout << "Exception type: const int *" << endl;
    }
}
