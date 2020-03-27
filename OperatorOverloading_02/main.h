#pragma once
/*
>> <<, [], ++ --, new delete, (),
*/
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
	for (size_t i = 0; i < m_length; i++)
	{
		if (i == m_length - 1)
			cout << m_p[i] << endl;
		else
			cout << m_p[i] << ", ";
	}
}




