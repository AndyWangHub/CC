#pragma once

#include<iostream>
using namespace std;

/*********************************************************************
函数模板（Function Template）实列
注意：typename，class，关键字功能一样
*/

//交换两个变量的值
template<typename T>  //模板头，这里不能有分号
void MySwap(T* a, T* b) //指针写法
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

//交换两个变量的值
template<class T>   //模板头，这里不能有分号
void MySwap(T& a, T& b) //引用写法
{
	T temp = a;
	a = b;
	b = temp;
}

//求三个数得分最大值
template<typename T>
T Max(T a, T b, T c)
{
	T max_num = a;
	if (b > max_num) max_num = b;
	if (c > max_num) max_num = c;
	return max_num;
}

/*********************************************************************
类模板（Class Template）实列
注意：typename，class，关键字功能一样
*/

/*
定义一个类来表示坐标，要求坐标的数据类型可以是整数、小数和字符串，例如：
x = 10、y = 10
x = 12.88、y = 129.65
x = "东经180度"、y = "北纬210度"
*/

template<typename T1, typename T2> //模板头
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
	T1 m_x; //x坐标
	T2 m_y; //y坐标
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
