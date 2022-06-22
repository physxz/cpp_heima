#include <iostream>
using namespace std;

class Person
{
public:
    static void func() // 静态成员函数
    {
        m_A = 100; // 静态成员函数可以访问静态成员变量
        // m_B = 200; // 错误，静态成员函数不可以访问非静态成员变量，无法区分到底是哪个对象的m_B属性
        cout << "static void func 调用" << endl;
    }
    static int m_A;
    int m_B;
// 静态成员函数也是有访问权限的
private:
    static void func2()
    {
        cout << "static void func2 调用" << endl;
    }
};

int Person::m_A = 0;

void test01()
{
    // 所有对象共享同一个函数
    Person p;
    // 1. 通过对象访问
    p.func();
    // 2. 通过类名访问
    Person::func();
    // Person::func2(); // 类外访问不到静态成员函数
}

int main() {
    test01();
    return 0;
}