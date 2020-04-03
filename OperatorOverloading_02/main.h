#pragma once
/*
>> <<, [], ++ --, new delete, (),
*/
#include <iomanip>
#include<iostream>
using namespace std;

/*
��̬������ɫ [] ���������
C++ �涨���±������[ ]�����Գ�Ա��������ʽ�������ء������غ��������е�������ʽ���£�
����ֵ���� & operator[ ] (����);
���ߣ�
const ����ֵ���� & operator[ ] (����) const;
ʹ�õ�һ��������ʽ��[ ]�������Է���Ԫ�أ��������޸�Ԫ�ء�ʹ�õڶ���������ʽ��[ ]ֻ�ܷ��ʶ������޸�Ԫ�ء�
��ʵ�ʿ����У�����Ӧ��ͬʱ�ṩ����������ʽ����������Ϊ����Ӧ const ������Ϊͨ�� const ����ֻ�ܵ��� const ��Ա������
������ṩ�ڶ�����ʽ����ô���޷����� const ������κ�Ԫ�ء�
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
	int m_length; //���鳤��
	int* m_p;  //ָ�������ڴ��ָ��
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
����++���Լ�--����һԪ�����������ǰ����ʽ�ͺ�����ʽ�����Ա����ء��뿴��������ӣ�
*/

class stopwatch
{
public:
	stopwatch():m_min(0),m_sec(0){}
	
	void setzero() { m_min = 0; m_sec = 0; }
	stopwatch run();
	stopwatch operator++(); //++i,ǰ�üӼ�
	stopwatch operator++(int); //i++,���üӼ�

	friend ostream& operator<<(ostream&, const stopwatch&);

private:
	int m_min;//��
	int m_sec;//��
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
����ǿ��ת��������ǵ�Ŀ�������Ҳ���Ա����أ���ֻ������Ϊ��Ա��������������Ϊȫ�ֺ�����
�����ʵ����غ�(������)��������Զ������ǿ������ת���ı��ʽ�͵ȼ��ڶ���.operator ������()��
����ɶ�����������ĵ��á�
*/

//����ĳ���� double ����ǿ��ת����������������ء�
class MyComplex
{
	double real, imag;
public:
	MyComplex(double r = 0, double i = 0) :real(r), imag(i) {};
	operator double() { return real; }  //����ǿ������ת������� double
};

/*
�ڴ��������� new��new[]��delete �� delete[] Ҳ���Խ������أ���������ʽ�ȿ�������ĳ�Ա������Ҳ������ȫ�ֺ�����һ������£��ڽ����ڴ����������͹����ˣ�ֻ������Ҫ�Լ������ڴ�ʱ�Ż����ء�

�Գ�Ա��������ʽ���� new �������
void * className::operator new( size_t size ){
	//TODO:
}

��ȫ�ֺ�������ʽ���� new �������
void * operator new( size_t size ){
	//TODO:
}

����������ʽ�ķ���ֵ��ͬ������void *���ͣ����Ҷ���һ��������Ϊsize_t���͡������� new �� new[] ʱ����������Ϊ��Ա����������Ϊȫ�ֺ��������ĵ�һ������������ size_t ���͡�size_t ��ʾ����Ҫ����ռ�Ĵ�С������ new[] �����غ������ԣ�size_t ���ʾ����Ҫ��������пռ���ܺ͡�
size_t ��ͷ�ļ� <cstdio> �б�����Ϊtypedef unsigned int size_t;��Ҳ�����޷������͡�
��Ȼ�����غ���Ҳ��������������������������Ĭ��ֵ�����ҵ�һ�����������ͱ����� size_t��

ͬ���ģ�delete �����Ҳ������������ʽ������ĳ�Ա��������ʽ�������أ�
void className::operator delete( void *ptr){
	//TODO:
}

��ȫ�ֺ�������ʽ�������أ�
void operator delete( void *ptr){
	//TODO:
}

����������ʽ�ķ���ֵ���� void ���ͣ����Ҷ�������һ�� void ���͵�ָ����Ϊ��������ָ��ָ����Ҫ�ͷŵ��ڴ�ռ䡣

*/


//********************************************************************//
/*
�� C++ �н������������ʱ��������������Ҫע�⣺
���غ�������ĺ���Ӧ�÷���ԭ���÷�ϰ�ߡ���������+���������ɵĹ��ܾ�Ӧ�����������ӷ��������ص�+��������������ǲ����ʵġ����⣬����Ӧ�������������ԭ�е����ԡ�
C++ �涨����������ز��ı�����������ȼ���
������������ܱ����أ�.��.*��::��? :��sizeof��
���������()��[]��->�����߸�ֵ�����=ʱ��ֻ�ܽ���������Ϊ��Ա��������������Ϊȫ�ֺ�����

��������ص�ʵ���ǽ����������Ϊһ��������ʹ��������ı��ʽ�ͱ�����Ϊ�����غ����ĵ��á�

�������������Ϊȫ�ֺ�������ʱ�����Ĳ�����������������Ĳ�����������������Ĳ������ͳ�Ϊ������ʵ�Ρ�

�����Ҳ��������Ϊ��Ա��������ʱ�����Ĳ�����������������Ĳ�����������һ��������Ĳ�������һ����Ϊ�������õĶ�������ĳ�Ϊ������ʵ�Ρ�

��Ҫʱ��Ҫ���ظ�ֵ�����=���Ա������������ڲ���ָ��ָ��ͬһƬ�洢�ռ䡣

�������������Ϊȫ�ֺ�����Ȼ������Ϊ�����Ԫ��

<<��>>���� iostream �б����أ��ų�Ϊ��ν�ġ���������������͡�����ȡ��������ġ�

���͵����ֿ�����Ϊǿ������ת���������Ҳ���Ա�����Ϊ��ĳ�Ա����������ʹ�ö����Զ�ת��Ϊĳ�����͡�

�������Լ�����������������ط�ʽ����������ǰ���÷��ͺ����÷���

��������ز��ı�����������ȼ������������ʱ��Ӧ�þ������������ԭ�������ԡ�
*/