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
	void setY(T2 y);

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
inline void Point<T1, T2>::setY(T2 y)
{
	m_y = y;
}


/*
��ģ��ʵ�ֿɱ䳤����
*/
template<class T>
class CArray
{
public:
	CArray(int s = 0); //s��������Ԫ�صĸ���
	CArray(CArray& a);
	~CArray();

	void push_back(const T& v); //����������β�����һ��Ԫ��v
	CArray& operator=(const CArray& a); //������������ĸ�ֵ
	T length() { return size; }
	T& operator[](int i)
	{//����֧�ָ����±��������Ԫ�أ���a[i] = 4��n = a[i]���������
		return ptr[i];
	}
	const T& operator[](int i)const
	{
		return ptr[i];
	}

private:
	int size; //����Ԫ�صĸ���
	T* ptr; //ָ��̬���������

};

template<class T>
inline CArray<T>::CArray(int s)
	:size(s)
{
	if (s == 0)
		ptr = NULL;
	else
		ptr = new T[s];
}

template<class T>
inline CArray<T>::CArray(CArray& a)
{
	if (!a.ptr)
	{
		ptr = NULL;
		size = 0;
		return;
	}
	ptr = new T[a.size];
	memcpy(ptr, a.ptr, sizeof(T) * a.size);
	size = a.size;
}

template<class T>
inline CArray<T>::~CArray()
{
	if (ptr) delete[]ptr;
}

template<class T>
inline void CArray<T>::push_back(const T& v)
{//������β�����һ��Ԫ��
	if (ptr)
	{
		T* tmpPtr = new T[size + 1]; //���·����ڴ�
		memcpy(tmpPtr, ptr, sizeof(T) * size); //����ԭ��������
		delete[]ptr;
		ptr = tmpPtr;
	}
	else //���鱾�����ǿյ�
		ptr = new T[1];

	ptr[size++] = v;
}

template<class T>
inline CArray<T>& CArray<T>::operator=(const CArray& a)
{
	// TODO: �ڴ˴����� return ���
	//��ֵ�ŵ�������ʹ"="��߶������ŵ����飬��С�����ݺ��ұߵĶ���һ��
	if (this == &a) //��ֹa=a������ֵ���³���
		return *this;
	if (a.ptr == NULL) //���a����������ǿյ�
	{
		if (ptr)
			delete[]ptr;
		ptr = NULL;
		size = 0;
		return *this;
	}
	if (size < a.size) //���ԭ�ռ乻�󣬾Ͳ��÷����µĿռ�
	{
		if (ptr)
			delete[]ptr;
		ptr = new T[a.size];
	}
	memcpy(ptr, a.ptr, sizeof(T) * a.size);
	size = a.size;
	return *this;
}
