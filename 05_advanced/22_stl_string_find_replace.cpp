#include <iostream>
using namespace std;

// 字符串查找和替换

// 1.查找

// find
void test01()
{
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    if (pos == -1)
    {
        cout << "未找到该字符串" << endl;
    }
    else
    {
    cout << "找到该字符串，pos = " << pos << endl;
    }

    // rfind从右向左查找(逆向搜寻)，find从左往右查找(正向搜寻)
    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;
}

// 2.替换
void test02()
{
    string str1 = "abcdef";
    str1.replace(1, 3, "1111"); // 从1号位置起3个字符，替换为"1111"
    cout << "str1 = " << str1 << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}