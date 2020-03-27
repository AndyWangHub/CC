#pragma once
/*
>> <<, [], ++ --, new delete, (),
*/
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
	for (size_t i = 0; i < m_length; i++)
	{
		if (i == m_length - 1)
			cout << m_p[i] << endl;
		else
			cout << m_p[i] << ", ";
	}
}




