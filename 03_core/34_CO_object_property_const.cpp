#include <iostream>
using namespace std;

class Person
{
public:
    Person() // 默认构造函数
    {

    }
// 常函数
    // this指针的本质是指针常量，指针的指向不可以修改
    // const Person * const this;
    void showPerson() const // 这里的const修饰的是this指向的值，this指向的值也不可以更改
    {
        // this->m_A = 100;
        // this = nullptr; // this指针不可以修改指针的指向的
        this->m_B = 100;
    }
    void func() {
        m_A = 100;
    }
    int m_A;
    mutable int m_B; // 加关键字mutable，特殊变量，即使在常函数中，也可以修改这个值
};

void test01()
{
    Person p;
    p.showPerson();
}

// 常对象
void test02()
{
    const Person p; // 常对象
    // p.m_A = 100; // 错误，常对象不能修改常函数内的成员变量
    p.m_B = 100; // 正确，mutable在常函数中仍可修改
    // 常对象只能调用常函数
    p.showPerson();
    // p.func(); // 常对象不能调用普通成员函数
}

int main() {
    test02();
    return 0;
}