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
	void setY(T2 y);

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
inline void Point<T1, T2>::setY(T2 y)
{
	m_y = y;
}


/*
类模板实现可变长数组
*/
template<class T>
class CArray
{
public:
	CArray(int s = 0); //s代表数组元素的个数
	CArray(CArray& a);
	~CArray();

	void push_back(const T& v); //用于在数组尾部添加一个元素v
	CArray& operator=(const CArray& a); //用于数组对象间的赋值
	T length() { return size; }
	T& operator[](int i)
	{//用于支持根据下标访问数组元素，如a[i] = 4和n = a[i]这样的语句
		return ptr[i];
	}
	const T& operator[](int i)const
	{
		return ptr[i];
	}

private:
	int size; //数组元素的个数
	T* ptr; //指向动态分配的数组

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
{//在数组尾部添加一个元素
	if (ptr)
	{
		T* tmpPtr = new T[size + 1]; //重新分配内存
		memcpy(tmpPtr, ptr, sizeof(T) * size); //拷贝原数组内容
		delete[]ptr;
		ptr = tmpPtr;
	}
	else //数组本来就是空的
		ptr = new T[1];

	ptr[size++] = v;
}

template<class T>
inline CArray<T>& CArray<T>::operator=(const CArray& a)
{
	// TODO: 在此处插入 return 语句
	//赋值号的作用是使"="左边对象里存放的数组，大小和内容和右边的对象一样
	if (this == &a) //防止a=a这样赋值导致出错
		return *this;
	if (a.ptr == NULL) //如果a里面的数组是空的
	{
		if (ptr)
			delete[]ptr;
		ptr = NULL;
		size = 0;
		return *this;
	}
	if (size < a.size) //如果原空间够大，就不用分配新的空间
	{
		if (ptr)
			delete[]ptr;
		ptr = new T[a.size];
	}
	memcpy(ptr, a.ptr, sizeof(T) * a.size);
	size = a.size;
	return *this;
}
