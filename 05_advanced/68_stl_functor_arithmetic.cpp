#include <iostream>
#include <functional>
using namespace std;

/*
内建函数对象-算数仿函数
- template <class T>T plus<T>; //加法仿函数
- template <class T>T minus<T>; //减法仿函数
- template <class T>T multiplies<T>; //乘法仿函数
- template <class T>T divides<T>; //除法仿函数
- template <class T>T modulus<T>; //取横仿函数
- template <class T>T negate<Y>; //取反仿函数
*/

void test01()
{
    negate<int> n;

    cout << n(50) << endl;
}

// plus 二元仿函数 加法
void test02()
{
    plus<int> p;
    cout << p(10, 20) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}