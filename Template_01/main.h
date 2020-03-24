#pragma once

#include<iostream>
using namespace std;

/*********************************************************************
����ģ�壨Function Template��ʵ��
ע�⣺typename��class���ؼ��ֹ���һ��
*/

//��������������ֵ
template<typename T>  //ģ��ͷ�����ﲻ���зֺ�
void MySwap(T* a, T* b) //ָ��д��
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

//��������������ֵ
template<class T>   //ģ��ͷ�����ﲻ���зֺ�
void MySwap(T& a, T& b) //����д��
{
	T temp = a;
	a = b;
	b = temp;
}

//���������÷����ֵ
template<typename T>
T Max(T a, T b, T c)
{
	T max_num = a;
	if (b > max_num) max_num = b;
	if (c > max_num) max_num = c;
	return max_num;
}

/*********************************************************************
��ģ�壨Class Template��ʵ��
ע�⣺typename��class���ؼ��ֹ���һ��
*/

/*
����һ��������ʾ���꣬Ҫ��������������Ϳ�����������С�����ַ��������磺
x = 10��y = 10
x = 12.88��y = 129.65
x = "����180��"��y = "��γ210��"
*/

template<typename T1, typename T2> //ģ��ͷ
class Point
{
public:
	Point(T1 x,T2 y)
		:m_x(x),m_y(y){}

	T1 getX();
	void setX(T1 x);

	T2 getY();
	void setY(T1 y);

private:
	T1 m_x; //x����
	T2 m_y; //y����
};

template<typename T1, typename T2>
inline T1 Point<T1, T2>::getX()
{
	return m_x;
}

template<typename T1, typename T2>
inline void Point<T1, T2>::setX(T1 x)
{
	m_x = x;
}

template<typename T1, typename T2>
inline T2 Point<T1, T2>::getY()
{
	return m_y;
}

template<typename T1, typename T2>
inline void Point<T1, T2>::setY(T1 y)
{
	m_y = y;
}
