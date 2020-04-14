#pragma once
/*
C++ �쳣������ƾͿ��������ǲ��񲢴�����Щ����
Ȼ�����ǿ����ó�������һ����������·������ִ�У�
���߲��ò��������򣬵��ڽ���ǰ������һЩ��Ҫ�Ĺ�����
���罫�ڴ��е�����д���ļ����رմ򿪵��ļ����ͷŷ�����ڴ�ȡ�
C++ �쳣������ƻ��漰 try��catch��throw �����ؼ���
*/
#include<iostream>
#include<string>
#include<exception>
using namespace std;

//�쳣�Ļ���ʹ��
void func_01()
{
	throw "Unknown Exception";  //�׳��쳣
	cout << "func_01: This statement will not be executed " << endl;
}

void func_02()
{
	func_01();
	cout << "func_02: This statement will not be executed " << endl;
}

int one()
{

	string str = "abc";
	try
	{
		char ch2 = str.at(40); //�±�Խ�磬�׳��쳣
		cout << ch2 << endl; //����Ĵ����׳��쳣�����治��ִ��
	}
	catch (exception&) //ֻ�ж��쳣���ͣ�����������
	{
		//catch�����쳣
		cout << "[1]out of bound!" << endl;
	}

#if 0
	try
	{
		char ch1 = str[40]; //�±�Խ�磬ch1Ϊ����ֵ��û���׳��쳣
		cout << ch1 << endl;
	}
	catch (const std::exception&)
	{
		//û���쳣�Ĵ������ֱ�ӱ���
		cout << "[2]out of bound!" << endl;
	}
#endif // 0

#if 0

	try {
		throw "Unknown Exception";  //throw���� �׳��쳣
		cout << "This statement will not be executed." << endl;
	}
	catch (const char* e) {
		cout << e << endl;
	}

#endif // 0

	/*
	�����쳣�󣬳����ִ���������ź����ĵ�������ǰ���ˣ�
	ֱ������ try ��ֹͣ����������˹����У���������ʣ�µĴ���
	�����к�����δ��ִ�еĴ��룩���ᱻ������û��ִ�еĻ�����
	*/
	try
	{
		//func_01(); //�����ú��������׳��쳣
		func_02(); 
	}
	catch (const char * e)
	{
		cout << e << endl;
	}

	return 0;
}