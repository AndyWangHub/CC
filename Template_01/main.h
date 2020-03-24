#pragma once

#include<iostream>
using namespace std;

/*
函数模板（Function Template）实列
注意：typename，class，关键字功能一样
*/

//交换两个变量的值
template<typename T>
void MySwap(T* a, T* b) //指针写法
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

//交换两个变量的值
template<class T>
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

/*
*/