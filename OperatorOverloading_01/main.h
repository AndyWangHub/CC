#pragma once
#include<iostream>
#include<cmath>
using namespace std;

/* 运算符重载规则
1) 并不是所有的运算符都可以重载。能够重载的运算符包括：
+  -  *  /  %  ^  &  |  ~  !  =  <  >  +=  -=  *=  /=  %=  ^=  &=  |=  <<  >>  <<=  >>=  ==  !=  <=  >=  &&  ||  ++  --  ,  ->*  ->  ()  []  new  new[]  delete  delete[]
2) 重载不能改变运算符的优先级和结合性。假设上一节的 complex 类中重载了+号和*号，并且 c1、c2、c3、c4 都是 complex 类的对象
3) 重载不会改变运算符的用法，原有有几个操作数、操作数在左边还是在右边，这些都不会改变。例如~号右边只有一个操作数，+号总是出现在两个操作数之间，重载后也必须如此。
4) 运算符重载函数不能有默认的参数，否则就改变了运算符操作数的个数，这显然是错误的。
5) 运算符重载函数既可以作为类的成员函数，也可以作为全局函数。
6) 箭头运算符->、下标运算符[ ]、函数调用运算符( )、赋值运算符=只能以成员函数的形式重载。

*/

//定义了一个复数类，通过运算符重载
//四则运算符（+、-、*、/、+=、-=、*=、/=）和关系运算符（>、<、<=、>=、==、!=）
//复数能够进行完整的四则运算，但不能进行完整的关系运算：我们只能判断两个复数是否相等，但不能比较它们的大小，所以不能对 >、<、<=、>= 进行重载
//需要注意的是，我们以全局函数的形式重载了 +、-、*、/、==、!=，以成员函数的形式重载了 +=、-=、*=、/=，而且应该坚持这样做
class MyComplex
{
public:
	MyComplex(double real, double imag);
public:
	//以全局函数形式重载
	friend MyComplex operator+(const MyComplex& c1, const MyComplex& c2);
	friend MyComplex operator-(const MyComplex& c1, const MyComplex& c2);
	friend MyComplex operator*(const MyComplex& c1, const MyComplex& c2);
	friend MyComplex operator/(const MyComplex& c1, const MyComplex& c2);
	friend bool operator==(const MyComplex& c1, const MyComplex& c2);
	friend bool operator!=(const MyComplex& c1, const MyComplex& c2);

	friend istream& operator>>(istream& in, MyComplex& c);
	friend ostream& operator<<(ostream& out, MyComplex& c);

	//以成员函数的形式重载
	MyComplex& operator+=(const MyComplex& c);
	MyComplex& operator-=(const MyComplex& c);
	MyComplex& operator*=(const MyComplex& c);
	MyComplex& operator/=(const MyComplex& c);

public: //成员函数
	inline double real() const { return m_real; }
	inline double imag() const { return m_imag; }
	inline void display() const
	{
		cout << m_real << " + " << m_imag << "i" << endl;
	}
private:
	double m_real; //实部
	double m_imag; //虚部
};


MyComplex::MyComplex(double real = 0.0, double imag = 0.0) //用默认值实现无参构造函数
	:m_real(real),m_imag(imag)
{
}

MyComplex operator+(const MyComplex& c1, const MyComplex& c2)
{
	return MyComplex(c1.m_real + c2.m_imag, c1.m_imag + c2.m_imag);
}

inline MyComplex operator-(const MyComplex& c1, const MyComplex& c2)
{
	MyComplex c;
	c.m_real = c1.m_real - c2.m_real;
	c.m_imag = c1.m_imag - c2.m_imag;
	return c;
}
//重载*运算符  (a+bi) * (c+di) = (ac-bd) + (bc+ad)i
inline MyComplex operator*(const MyComplex& c1, const MyComplex& c2)
{
	MyComplex c;
	c.m_real = c1.m_real * c2.m_real - c1.m_imag * c2.m_imag;
	c.m_imag = c1.m_imag * c2.m_real + c1.m_real * c2.m_imag;
	return c;
}
//重载/运算符  (a+bi) / (c+di) = [(ac+bd) / (c²+d²)] + [(bc-ad) / (c²+d²)]i
inline MyComplex operator/(const MyComplex& c1, const MyComplex& c2)
{
	MyComplex c;
	c.m_real = (c1.m_real * c2.m_real + c1.m_imag * c2.m_imag) / (c2.m_real * c2.m_real + c2.m_imag * c2.m_imag);
	c.m_imag = (c1.m_imag * c2.m_real - c1.m_real * c2.m_imag) / (pow(c2.m_real, 2) + pow(c2.m_imag, 2));
	return c;
}

inline bool operator==(const MyComplex& c1, const MyComplex& c2)
{
	if (c1.m_real == c2.m_real && c1.m_imag == c2.m_imag)
		return true;
	else
		return false;
}

inline bool operator!=(const MyComplex& c1, const MyComplex& c2)
{
	if (c1.m_real != c2.m_real || c1.m_imag != c2.m_imag)
		return true;
	else
		return false;
}

inline istream& operator>>(istream& in, MyComplex& c)
{
	in >> c.m_real >> c.m_imag;
	return in;
}

inline ostream& operator<<(ostream& out, MyComplex& c)
{
	out << c.m_real << " + " << c.m_imag << " i";
	return out;
}

inline MyComplex& MyComplex::operator+=(const MyComplex& c)
{
	this->m_real += c.m_real;
	this->m_imag += c.m_imag;
	return *this;
}

inline MyComplex& MyComplex::operator-=(const MyComplex& c)
{
	this->m_real -= c.m_real;
	this->m_imag -= c.m_imag;
	return *this;
}

inline MyComplex& MyComplex::operator*=(const MyComplex& c)
{
	// TODO: 在此处插入 return 语句
	this->m_real = ((*this) * c).m_real;
	this->m_imag = ((*this) * c).m_imag;
	return *this;
}

inline MyComplex& MyComplex::operator/=(const MyComplex& c)
{
	this->m_real = (this->m_real * c.m_real + this->m_imag * c.m_imag) / (pow(c.m_real, 2) + pow(c.m_imag, 2));
	this->m_imag = (this->m_imag * c.m_real - this->m_real * c.m_imag) / (pow(c.m_real, 2) + pow(c.m_imag, 2));
	return *this;
}