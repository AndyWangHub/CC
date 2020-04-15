#pragma once
/*
�ܳ����ڸ�ֵ����ߵı��ʽ��Ϊ����ֵ�������ܳ����ڸ�ֵ����ߵı��ʽ��Ϊ����ֵ����
һ����˵����ֵ�ǿ���ȡ��ַ�ģ���ֵ�򲻿��ԡ�
�� const �ı���������ֵ���������õķ���ֵ���������ã�
��ú������þ�����ֵ��ǰ����ѧ�ġ����á��������ñ����ģ�
����������ֵ��������Ƕ��ǡ���ֵ���á���
C++11 ������һ�����ã�����������ֵ�������Ϊ����ֵ���á���
��������ʱ�������ܳ����ڸ�ֵ����ߣ��������ֵ����ֵ���þͿ���������������ʱ������
���� && ������ = ��ֵ���ʽ;
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
	MyString(const MyString& s) //���ƹ��캯��
	{
		cout << "copy constuctor called" << endl;
		str = new char[strlen(s.str)];
		strcpy(str, s.str);
	}
	MyString& operator = (const MyString& s) //���Ƹ��ƺ�
	{
		cout << "copy operator = called" << endl;
		if (str != s.str)
		{
			delete[] str;
			str = new char[strlen(s.str) + 1];
			strcpy(str, s.str);
		}
	}

	MyString(MyString&& s) //�ƶ����캯��
		:str(s.str)
	{
		cout << "move constructo called" << endl;
		s.str = new char[1];
		s.str[0] = 0;
	}

	MyString& operator=(MyString&& s) //�ƶ���ֵ��
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
	T tmp(std::move(a));//std::move(a) Ϊ��ֵ�����������ƶ����캯��
	a = std::move(b);  //move(b) Ϊ��ֵ��������������ƶ���ֵ��
	b = move(tmp);//move(tmp) Ϊ��ֵ��������������ƶ���ֵ��
}


class AA{};
void Rvalue()
{
	//AA& r1 = AA(); //����������ʱ����A()����ֵ����˲��ܳ�ʼ����ֵ����r1
	AA&& r2 = AA(); //��ȷ����r2����ֵ����

	MyString s;
	s = MyString("this"); //�����ƶ���ֵ��
	cout << "* * * *" << endl;
	cout << s.str << endl;

	MyString s1 = "hello", s2 = "world";
	MoveSwap(s1, s2);  //����һ���ƶ����캯���������ƶ���ֵ��
	cout << s2.str << endl;
}
