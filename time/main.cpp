#include<iostream>
#include<time.h>
#include <windows.h>

using namespace std;

int main()
{

	/*
	ͨ��windowAPI��ȡ����ʱ�䣬��ȷ������
	*/
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d %02d:%02d:%02d.%03d ����%1d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);

	system("pause");
	return 0;
}