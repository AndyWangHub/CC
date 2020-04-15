#pragma once
/*
能出现在赋值号左边的表达式称为“左值”，不能出现在赋值号左边的表达式称为“右值”。
一般来说，左值是可以取地址的，右值则不可以。
非 const 的变量都是左值。函数调用的返回值若不是引用，
则该函数调用就是右值。前面所学的“引用”都是引用变量的，
而变量是左值，因此它们都是“左值引用”。
C++11 新增了一种引用，可以引用右值，因而称为“右值引用”。
无名的临时变量不能出现在赋值号左边，因而是右值。右值引用就可以引用无名的临时变量。
类型 && 引用名 = 右值表达式;
*/

#include<iostream>
#include<cstdlib>
using namespace std;

class MyString
{
public:
	MyString() 
		:str(new char[1])
	{
		str[0] = 0;
	}
	MyString(const char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	MyString(const MyString& s) //复制构造函数
	{
		cout << "copy constuctor called" << endl;
		str = new char[strlen(s.str)];
		strcpy(str, s.str);
	}
	MyString& operator = (const MyString& s) //复制复制号
	{
		cout << "copy operator = called" << endl;
		if (str != s.str)
		{
			delete[] str;
			str = new char[strlen(s.str) + 1];
			strcpy(str, s.str);
		}
	}

	MyString(MyString&& s) //移动构造函数
		:str(s.str)
	{
		cout << "move constructo called" << endl;
		s.str = new char[1];
		s.str[0] = 0;
	}

	MyString& operator=(MyString&& s) //移动赋值号
	{
		cout << "move operator = called" << endl;
		if (str != s.str) 
		{
			str = s.str;
			s.str = new char[1];
			s.str[0] = 0;
		}
		return *this;
	}

	~MyString()
	{
		delete[] str;
	}

public:
	char* str;
};

template<class T>
void MoveSwap(T& a, T& b)
{
	T tmp(std::move(a));//std::move(a) 为右值，这里会调用移动构造函数
	a = std::move(b);  //move(b) 为右值，因此这里会调用移动赋值号
	b = move(tmp);//move(tmp) 为右值，因此这里会调用移动赋值号
}


class AA{};
void Rvalue()
{
	//AA& r1 = AA(); //错误，无名临时变量A()是右值，因此不能初始化左值引用r1
	AA&& r2 = AA(); //正确，因r2是右值引用

	MyString s;
	s = MyString("this"); //调用移动赋值号
	cout << "* * * *" << endl;
	cout << s.str << endl;

	MyString s1 = "hello", s2 = "world";
	MoveSwap(s1, s2);  //调用一次移动构造函数和两次移动赋值号
	cout << s2.str << endl;
}
