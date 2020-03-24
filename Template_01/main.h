#pragma once

#include<iostream>
using namespace std;

/*
����ģ�壨Function Template��ʵ��
ע�⣺typename��class���ؼ��ֹ���һ��
*/

//��������������ֵ
template<typename T>
void MySwap(T* a, T* b) //ָ��д��
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

//��������������ֵ
template<class T>
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

/*
*/