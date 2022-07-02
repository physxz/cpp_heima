#include <iostream>
#include <string>
using namespace std;

/*
string的构造函数
- string(); // 创建一个孔的字符串，例如：string str;
  string(const char* s); // 使用字符串s初始化
- string(const string& str); // 使用一个string对象初始化另一个string对象 拷贝构造
- string(int n, char c);
*/

void test01()
{
    string s1; // 默认构造
    const char * str = "hello world"; // c语言风格字符串
    string s2(str);
    cout << "s2 = " << s2 << endl;
    string s3(s2); // 拷贝构造
    cout << "s3 = " << s3 << endl;
    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;
}

int main()
{
    test01();
    return 0;
}