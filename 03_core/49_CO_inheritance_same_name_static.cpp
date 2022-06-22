#include <iostream>
using namespace std;

class Base
{
public:
    static void func()
    {
        cout << "Base static void func()调用" << endl;
    }
    static void func(int a)
    {
        cout << "Base static void func()调用" << endl;
    }
    static int m_A;
};
int Base::m_A = 100;

class Son : public Base
{
public:
    static void func()
    {
        cout << "Son static void func()调用" << endl;
    }
    static int m_A;
};
int Son::m_A = 200;

// 同名静态成员属性
void test01()
{
    // 静态成员访问方式：
    // 1. 通过对象访问
    cout << "通过对象访问：" << endl;
    Son s;
    cout << "Son m_A = " << s.m_A << endl;
    cout << "Base m_A = " << s.Base::m_A << endl;
    // 2. 通过类名访问
    cout << "通过类名访问：" << endl;
    cout << "Son m_A = " << Son::m_A << endl;
    // 第一个::代表通过类名方式访问，第二个::代表访问父类作用域下的成员
    cout << "Base m_A = " << Son::Base::m_A << endl; // 通过子类访问父类中的成员变量
}

// 同名静态成员函数
void test02()
{
    // 1. 通过对象访问
    cout << "通过对象访问：" << endl;
    Son s;
    s.func();
    s.Base::func();
    s.Base::func(2); // 需要加作用域
    // 2. 通过类名访问
    cout << "通过类名访问：" << endl;
    Son::func();
    Son::Base::func();
}

int main() {
    // test01();
    test02();
    return 0;
}