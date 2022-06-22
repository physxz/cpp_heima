#include <iostream>
using namespace std;

// 成员变量和成员函数是分开存储的
class Person
{
    // 类为空时 sizeof(p)=1 每个空对象也有一个对应的内存空间
    int m_A; // 非静态成员变量 sizeof(p)=4 属于类的对象(p是类的一个对象)上
    static int m_B; // 静态成员变量 sizeof(p)=4 不属于类的对象上
    void func() {} // 非静态成员函数 sizeof(p)=4 不属于类的对象上
    static void func2() {} // 静态成员函数 sizeof(p)=4 不属于类的对象上
    int m_C; // 非静态成员变量 sizeof(p)=8 m_A和m_C总共占8个字节
};

int Person::m_B = 0;

void test01()
{
    Person p; // 实例化，产生对象
    // 空对象占用1个字节
    // C++编译器会给每个空对象也分配1个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
    cout << "size of p = " << sizeof(p) << endl;
}

void test02()
{
    Person p;
    cout << "size of p = " << sizeof(p) << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}