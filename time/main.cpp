#include<iostream>
#include<time.h>
#include <windows.h>

using namespace std;

int main()
{

	/*
	通过windowAPI获取本地时间，精确到毫秒
	*/
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);

	system("pause");
	return 0;
}