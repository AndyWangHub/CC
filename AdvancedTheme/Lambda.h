/*
使用 STL 时，往往会大量用到函数对象，为此要编写很多函数对象类。
有的函数对象类只用来定义了一个对象，而且这个对象也只使用了一次，
编写这样的函数对象类就有点浪费。

而且，定义函数对象类的地方和使用函数对象的地方可能相隔较远，看到函数对象，
想要查看其 operator() 成员函数到底是做什么的也会比较麻烦。

对于只使用一次的函数对象类，能否直接在使用它的地方定义呢？Lambda 表达式能够解决这个问题。
使用 Lambda 表达式可以减少程序中函数对象类的数量，使得程序更加优雅。

Lambda 表达式的定义形式如下：
[外部变量访问方式说明符] (参数表) -> 返回值类型
{
   语句块
}

其中，“外部变量访问方式说明符”可以是=或&，表示{}中用到的、定义在{}外面的变量在{}中是否允许被改变。
=表示不允许，&表示允许。当然，在{}中也可以不使用定义在外面的变量。“-> 返回值类型”可以省略。

下面是一个合法的Lambda表达式：
[=] (int x, int y) -> bool {return x%10 < y%10; }
*/

#pragma once
#include<iostream>
#include <algorithm>
#include<cstdlib>
using namespace std;

void Lambda()
{
    int a[4] = { 1,2,3,4 };
    int total = 0;
    for_each(a, a + 4, [&](int& x)
        {
            total += x;
            x *= 2;
        });
    cout << total << endl; //输出 10

    for_each(a, a + 4, [=](int x)
        {
            cout << x << " ";
        });

    cout << endl;
}