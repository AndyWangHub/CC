/*
Ҫȷ���� new ��̬������ڴ�ռ��ڳ���ĸ���ִ��·�����ܱ��ͷ���һ���鷳�����顣
C++ 11 ģ���� <memory> ͷ�ļ��ж��������ָ�룬�� shared _ptr ģ�壬�����������ֽ���������ġ�

ֻҪ�� new ��������ص�ָ�� p ����һ�� shared_ptr �����йܡ���
�Ͳ��ص���������дdelete p��䡪��ʵ���ϸ�������Ҫ��д������䣬
�й� p �� shared_ptr ����������ʱ���Զ�ִ��delete p�����ң�
�� shared_ptr ��������ָ�� p ����ʹ�ã��������й� p �� shared_ptr ������� ptr��
��ô *ptr ���� p ָ��Ķ���

ͨ�� shared_ptr �Ĺ��캯���������� shared_ptr �����й�һ�� new ��������ص�ָ�룬д�����£�
shared_ptr<T> ptr(new T);  // T ������ int��char����ȸ�������
�˺�ptr �Ϳ����� T* ���͵�ָ��һ��ʹ�ã��� *ptr ������ new ��̬������Ǹ�����
��� shared_ptr ������Թ�ͬ�й�һ��ָ�� p�������������й� p �� shared_ptr ���󶼽���˶�����й�ʱ���ͻ�ִ��delete p��
*/
#pragma once
#include<iostream>
#include<cstdlib>
#include<memory>
using namespace std;

class A
{
public:
	int i;
	A(int n) :i(n) {};
	~A() { cout << i << " destructed" << endl; }
};

void SmartPointer()
{
	std::shared_ptr<A> sp1(new A(2)); //A(2)��sp1�йܣ�
	shared_ptr<A> sp2(sp1); //A(2)ͬʱ����sp2�й�
	shared_ptr<A> sp3;
	sp3 = sp2; //A(2)ͬʱ����sp3�й�
	cout << sp1->i << "," << sp2->i << "," << sp3->i << endl;

	A* p = sp3.get(); // get�����йܵ�ָ�룬p ָ�� A(2)
	cout << p->i << endl;  //��� 2

	sp1.reset(new A(3));    // reset�����й��µ�ָ��, ��ʱsp1�й�A(3)
	sp2.reset(new A(4));    // sp2�й�A(4)
	cout << sp1->i << endl; //��� 3
	sp3.reset(new A(5));    // sp3�й�A(5),A(2)�����йܣ���delete

	cout << "end" << endl;
}

/*
ע�⣬����������ķ�ʽʹ������ shared_ptr �����й�ͬһ��ָ�룺
A* p = new A(10);
shared_ptr <A> sp1(p), sp2(p);
sp1 �� sp2 �����Ṳ��ͬһ���� p ���йܼ��������Ǹ��Խ��� p ���йܼ�������Ϊ 1��sp2 �޷�֪�� p �Ѿ��� sp1 �йܹ�����
�������� sp1 ����ʱҪ���� p��sp2 ����ʱҪ�ٴ����� p����ᵼ
*/