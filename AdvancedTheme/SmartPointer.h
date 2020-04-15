/*
要确保用 new 动态分配的内存空间在程序的各条执行路径都能被释放是一件麻烦的事情。
C++ 11 模板库的 <memory> 头文件中定义的智能指针，即 shared _ptr 模板，就是用来部分解决这个问题的。

只要将 new 运算符返回的指针 p 交给一个 shared_ptr 对象“托管”，
就不必担心在哪里写delete p语句——实际上根本不需要编写这条语句，
托管 p 的 shared_ptr 对象在消亡时会自动执行delete p。而且，
该 shared_ptr 对象能像指针 p —样使用，即假设托管 p 的 shared_ptr 对象叫作 ptr，
那么 *ptr 就是 p 指向的对象。

通过 shared_ptr 的构造函数，可以让 shared_ptr 对象托管一个 new 运算符返回的指针，写法如下：
shared_ptr<T> ptr(new T);  // T 可以是 int、char、类等各种类型
此后，ptr 就可以像 T* 类型的指针一样使用，即 *ptr 就是用 new 动态分配的那个对象。
多个 shared_ptr 对象可以共同托管一个指针 p，当所有曾经托管 p 的 shared_ptr 对象都解除了对其的托管时，就会执行delete p。
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
	std::shared_ptr<A> sp1(new A(2)); //A(2)由sp1托管，
	shared_ptr<A> sp2(sp1); //A(2)同时交给sp2托管
	shared_ptr<A> sp3;
	sp3 = sp2; //A(2)同时交有sp3托管
	cout << sp1->i << "," << sp2->i << "," << sp3->i << endl;

	A* p = sp3.get(); // get返回托管的指针，p 指向 A(2)
	cout << p->i << endl;  //输出 2

	sp1.reset(new A(3));    // reset导致托管新的指针, 此时sp1托管A(3)
	sp2.reset(new A(4));    // sp2托管A(4)
	cout << sp1->i << endl; //输出 3
	sp3.reset(new A(5));    // sp3托管A(5),A(2)无人托管，被delete

	cout << "end" << endl;
}

/*
注意，不能用下面的方式使得两个 shared_ptr 对象托管同一个指针：
A* p = new A(10);
shared_ptr <A> sp1(p), sp2(p);
sp1 和 sp2 并不会共享同一个对 p 的托管计数，而是各自将对 p 的托管计数都记为 1（sp2 无法知道 p 已经被 sp1 托管过）。
这样，当 sp1 消亡时要析构 p，sp2 消亡时要再次析构 p，这会导
*/