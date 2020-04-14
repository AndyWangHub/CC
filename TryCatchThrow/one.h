#pragma once
/*
C++ 异常处理机制就可以让我们捕获并处理这些错误，
然后我们可以让程序沿着一条不会出错的路径继续执行，
或者不得不结束程序，但在结束前可以做一些必要的工作，
例如将内存中的数据写入文件、关闭打开的文件、释放分配的内存等。
C++ 异常处理机制会涉及 try、catch、throw 三个关键字
*/
#include<iostream>
#include<string>
#include<exception>
using namespace std;

//异常的基本使用
void func_01()
{
	throw "Unknown Exception";  //抛出异常
	cout << "func_01: This statement will not be executed " << endl;
}

void func_02()
{
	func_01();
	cout << "func_02: This statement will not be executed " << endl;
}

int one()
{

	string str = "abc";
	try
	{
		char ch2 = str.at(40); //下标越界，抛出异常
		cout << ch2 << endl; //上面的代码抛出异常后下面不在执行
	}
	catch (exception&) //只判断异常类型，不接受数据
	{
		//catch捕获到异常
		cout << "[1]out of bound!" << endl;
	}

#if 0
	try
	{
		char ch1 = str[40]; //下标越界，ch1为垃圾值，没有抛出异常
		cout << ch1 << endl;
	}
	catch (const std::exception&)
	{
		//没有异常的处理程序直接崩溃
		cout << "[2]out of bound!" << endl;
	}
#endif // 0

#if 0

	try {
		throw "Unknown Exception";  //throw设置 抛出异常
		cout << "This statement will not be executed." << endl;
	}
	catch (const char* e) {
		cout << e << endl;
	}

#endif // 0

	/*
	发生异常后，程序的执行流会沿着函数的调用链往前回退，
	直到遇见 try 才停止。在这个回退过程中，调用链中剩下的代码
	（所有函数中未被执行的代码）都会被跳过，没有执行的机会了
	*/
	try
	{
		//func_01(); //被调用函数里面抛出异常
		func_02(); 
	}
	catch (const char * e)
	{
		cout << e << endl;
	}

	return 0;
}