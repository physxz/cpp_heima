#include <iostream>
#include <string>
using namespace std;

class Phone
{
public:
    Phone(string pName)
    {
        cout << "Phone的构造函数调用" << endl;
        m_PName = pName;
    }
    ~Phone()
    {
        cout << "Phone的析构函数调用" << endl;
    }
    string m_PName;
};

class Person
{
public:
    // Phone m_Phone = pName; 隐式转换法
    Person(string name, string pName): m_Name(name), m_Phone(pName)
    {
        cout << "Person的构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
    string m_Name;
    Phone m_Phone;
};

// 当其他类对象作为本类成员，构造时先构造类对象，再构造自身
// 析构的顺序与构造相反(栈区先进后出)

void test01()
{
    Person p("张三", "苹果MAX");
    cout << p.m_Name << "拿着" << p.m_Phone.m_PName << "手机" << endl;
}

int main() {
    test01();
    return 0;
}