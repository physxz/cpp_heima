#include <iostream>
#include <string>
using namespace std;

// string字符串存取

// char& operator[](int n); // 通过[]方式获取字符
// char& at[int n]; // 通过at方式获取字符

void test01()
{
    string str = "hello";
    // cout << "str = " << str << endl;

    // 读取
    // 1.通过[]方式访问字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    // 2.通过at方式访问字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << "-";
    }
    cout << endl;

    // 修改单个字符
    str[0] = 'x';
    cout << "str = " << str << endl;
    str.at(1) = 'x';
    cout << "str = " << str << endl;
}

int main()
{
    test01();
    return 0;
}