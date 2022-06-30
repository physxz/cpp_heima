#include <iostream>
using namespace std;

/**
 * 普通函数与模板函数的区别
*/

// 普通函数
int myAdd01(int a, int b)
{
    return a+b;
}

// 函数模板
template<typename T>
T myAdd02(T a, T b)
{
    return a+b;
}

void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << "*****普通函数*****" << endl;
    cout << "a + b = " << myAdd01(a,b) << endl; // 30
    cout << "a + c = " << myAdd01(a,c) << endl; // c=99，结果109，隐式类型转换
    cout << "*****函数模板*****" << endl;
    cout << "a + b = " << myAdd02(a,b) << endl; // 30
    // cout << "a + c = " << myAdd02(a,c) << endl; // 错误，二义性，类型不统一
    cout << "a + c = " << myAdd02<int>(a,c) << endl; // 109，char转为int类型
}

int main()
{
    test01();
    return 0;
}