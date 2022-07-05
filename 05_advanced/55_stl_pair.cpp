#include <iostream>
#include <string>
using namespace std;

// pair对组创建
// 成对出现的数据，利用对组可以返回两个数据

void test01()
{
    // 第一种方式：有参构造
    pair<string, int> p("Tom", 20);
    cout << "姓名：" << p.first << "\t" << "年龄：" << p.second << endl;

    // 第二种方式：make_pair(first, second);
    pair<string, int> p2 = make_pair("Jerry", 18);
    cout << "姓名：" << p2.first << "\t" << "年龄：" << p2.second << endl;
}

int main()
{
    test01();
    return 0;
}