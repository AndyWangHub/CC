#pragma once

#include<iostream>
#include<string>
#include<exception>
using namespace std;

//�Զ�����쳣����
class OutOfRange
{
public:
	OutOfRange()
		:m_flag(1),m_len(0),m_index(0){}
	OutOfRange(int len, int index)
		:m_len(len), m_index(index), m_flag(2) {}

	void what() const; //��ȡ����Ĵ�����Ϣ
private:
	int m_flag; //��ͬ��flag��ʾ��ͬ�Ĵ���
	int m_len; //��ǰ���鳤��
	int m_index; //��ǰʹ�õ������±�
};

void OutOfRange::what() const
{
	if (m_flag == 1) {
		cout << "Error: empty array, no elements to pop." << endl;
	}
	else if (m_flag == 2) {
		cout << "Error: out of range( array length " << m_len << ", access index " << m_index << " )" << endl;
	}
	else {
		cout << "Unknown exception." << endl;
	}
}

class Array
{
public:
	Array();
	~Array() { free(m_p); }

	int operator[](int index)const;//��ȡ����Ԫ��
	int push(int ele);//��β������Ԫ��
	int pop(); //��β��ɾ������Ԫ��
	int length()const { return m_len; } //��ȡ���鳤��

private:
	int m_len; //���鳤��
	int m_capacity; //��ǰ���ڴ�����
	int* m_p;//�ڴ�ָ��
private:
	static const int m_stepSize = 50; //ÿ�����ݵĲ���
};

Array::Array()
{
	m_p = (int*)malloc(sizeof(int) * m_stepSize);
	m_capacity = m_stepSize;
	m_len = 0;
}

inline int Array::operator[](int index) const
{
	if (index < 0 || index >= m_len) //�ж��Ƿ�Խ��
	{
		throw OutOfRange(m_len, index);//�׳��쳣������һ����������
	}
	return *(m_p + index);
}

inline int Array::push(int ele)
{
	if (m_len >= m_capacity) // ����������������
	{
		m_capacity += m_stepSize; 
		m_p = (int*)realloc(m_p, sizeof(int) * m_capacity);//����
	}
	*(m_p + m_len) = ele;
	m_len++;
	return m_len - 1;
}

inline int Array::pop()
{
	if (m_len == 0)
	{
		throw OutOfRange();//�׳��쳣������һ����������
	}
	m_len--;
	return *(m_p + m_len);
}

//��ӡ����Ԫ��
void printArray(Array& arr)
{
	int len = arr.length();

	//�ж������Ƿ�Ϊ��
	if (len == 0)
	{
		cout << "Empty array! No elements to print." << endl;
		return;
	}

	for (int i = 0; i < len; i++) 
	{
		if (i == len - 1) {
			cout << arr[i] << endl;
		}
		else {
			cout << arr[i] << ", ";
		}
	}

}

void three()
{
	Array nums;
	//�����������ʮ��Ԫ��
	for (size_t i = 0; i < 10; i++)
	{
		nums.push(i);
	}
	printArray(nums);

	//���Է��ʵ�20��Ԫ��
	try
	{
		cout << nums[20] << endl;
	}
	catch (const OutOfRange &e)
	{
		e.what();
	}

	//����ɾ��20��Ԫ��
	try
	{
		for (size_t i = 0; i < 20U; i++)
		{
			nums.pop();
		}
	}
	catch (const OutOfRange& e)
	{
		e.what();
	}

	printArray(nums);
}


