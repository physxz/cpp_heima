#include <iostream>
#include <string>
using namespace std;

// 字符串子串

void test01()
{
    string str = "abcdef";
    string subStr = str.substr(1, 3);
    cout << "subsSr = " << subStr << endl;
}

// 实用操作(获取邮箱用户名)
void test02()
{
    string email = "zhangsan@sina.com";
    // 从邮件地址中获取用户名信息
    int pos = email.find("@");
    string username = email.substr(0, pos);
    cout << "username = " << username << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}