#pragma once
/*
>> <<, [], ++ --, new delete, (),
*/
#include <iomanip>
#include<iostream>
using namespace std;

/*
动态数组颜色 [] 运算符重载
C++ 规定，下标运算符[ ]必须以成员函数的形式进行重载。该重载函数在类中的声明格式如下：
返回值类型 & operator[ ] (参数);
或者：
const 返回值类型 & operator[ ] (参数) const;
使用第一种声明方式，[ ]不仅可以访问元素，还可以修改元素。使用第二种声明方式，[ ]只能访问而不能修改元素。
在实际开发中，我们应该同时提供以上两种形式，这样做是为了适应 const 对象，因为通过 const 对象只能调用 const 成员函数，
如果不提供第二种形式，那么将无法访问 const 对象的任何元素。
*/
class MyArray
{
public:
	MyArray(int length = 0);
	~MyArray();

	int& operator[](int i);
	const int& operator[](int i) const;

	int length() const { return m_length; }
	void display() const;

private:
	int m_length; //数组长度
	int* m_p;  //指向数组内存的指针
};



inline MyArray::MyArray(int length)
	:m_length(length)
{
	if (length == 0)
		m_p = NULL;
	else
		m_p = new int[length];
}

MyArray::~MyArray()
{
	if (m_length != 0)
	{
		delete[] m_p;
		m_p = NULL;
		m_length = 0;
	}
}

inline int& MyArray::operator[](int i)
{
	return m_p[i];
}

inline const int& MyArray::operator[](int i) const
{
	return m_p[i];
}

inline void MyArray::display() const
{
	for (int i = 0; i < m_length; i++)
	{
		if (i == m_length - 1)
			cout << m_p[i] << endl;
		else
			cout << m_p[i] << ", ";
	}
}


/*
自增++和自减--都是一元运算符，它的前置形式和后置形式都可以被重载。请看下面的例子：
*/

class stopwatch
{
public:
	stopwatch():m_min(0),m_sec(0){}
	
	void setzero() { m_min = 0; m_sec = 0; }
	stopwatch run();
	stopwatch operator++(); //++i,前置加加
	stopwatch operator++(int); //i++,后置加加

	friend ostream& operator<<(ostream&, const stopwatch&);

private:
	int m_min;//分
	int m_sec;//秒
};

stopwatch stopwatch::run()
{
	++m_sec;
	if (m_sec == 60)
	{
		m_min++;
		m_sec = 0;
	}
	return *this;
}

inline stopwatch stopwatch::operator++()
{
	return run();
}

inline stopwatch stopwatch::operator++(int n)
{
	stopwatch s = *this;
	run();
	return s;
}

ostream& operator<<(ostream& out, const stopwatch& s)
{
	out << setfill('0') << setw(2) << s.m_min << ":" << setw(2) << s.m_sec;
	return out;
}

/*
类型强制转换运算符是单目运算符，也可以被重载，但只能重载为成员函数，不能重载为全局函数。
经过适当重载后，(类型名)对象这个对对象进行强制类型转换的表达式就等价于对象.operator 类型名()，
即变成对运算符函数的调用。
*/

//下面的程序对 double 类型强制转换运算符进行了重载。
class MyComplex
{
	double real, imag;
public:
	MyComplex(double r = 0, double i = 0) :real(r), imag(i) {};
	operator double() { return real; }  //重载强制类型转换运算符 double
};

/*
内存管理运算符 new、new[]、delete 和 delete[] 也可以进行重载，其重载形式既可以是类的成员函数，也可以是全局函数。一般情况下，内建的内存管理运算符就够用了，只有在需要自己管理内存时才会重载。

以成员函数的形式重载 new 运算符：
void * className::operator new( size_t size ){
	//TODO:
}

以全局函数的形式重载 new 运算符：
void * operator new( size_t size ){
	//TODO:
}

两种重载形式的返回值相同，都是void *类型，并且都有一个参数，为size_t类型。在重载 new 或 new[] 时，无论是作为成员函数还是作为全局函数，它的第一个参数必须是 size_t 类型。size_t 表示的是要分配空间的大小，对于 new[] 的重载函数而言，size_t 则表示所需要分配的所有空间的总和。
size_t 在头文件 <cstdio> 中被定义为typedef unsigned int size_t;，也就是无符号整型。
当然，重载函数也可以有其他参数，但都必须有默认值，并且第一个参数的类型必须是 size_t。

同样的，delete 运算符也有两种重载形式。以类的成员函数的形式进行重载：
void className::operator delete( void *ptr){
	//TODO:
}

以全局函数的形式进行重载：
void operator delete( void *ptr){
	//TODO:
}

两种重载形式的返回值都是 void 类型，并且都必须有一个 void 类型的指针作为参数，该指针指向需要释放的内存空间。

*/


//********************************************************************//
/*
在 C++ 中进行运算符重载时，有以下问题需要注意：
重载后运算符的含义应该符合原有用法习惯。例如重载+运算符，完成的功能就应该类似于做加法，在重载的+运算符中做减法是不合适的。此外，重载应尽量保留运算符原有的特性。
C++ 规定，运算符重载不改变运算符的优先级。
以下运算符不能被重载：.、.*、::、? :、sizeof。
重载运算符()、[]、->、或者赋值运算符=时，只能将它们重载为成员函数，不能重载为全局函数。

运算符重载的实质是将运算符重载为一个函数，使用运算符的表达式就被解释为对重载函数的调用。

运算符可以重载为全局函数。此时函数的参数个数就是运算符的操作数个数，运算符的操作数就成为函数的实参。

运算符也可以重载为成员函数。此时函数的参数个数就是运算符的操作数个数减一，运算符的操作数有一个成为函数作用的对象，其余的成为函数的实参。

必要时需要重载赋值运算符=，以避免两个对象内部的指针指向同一片存储空间。

运算符可以重载为全局函数，然后声明为类的友元。

<<和>>是在 iostream 中被重载，才成为所谓的“流插入运算符”和“流提取运算符”的。

类型的名字可以作为强制类型转换运算符，也可以被重载为类的成员函数。它能使得对象被自动转换为某种类型。

自增、自减运算符各有两种重载方式，用于区别前置用法和后置用法。

运算符重载不改变运算符的优先级。重载运算符时，应该尽量保留运算符原本的特性。
*/