#include <iostream>
using namespace std;

class Person
{
public:
    // 1. 通过成员函数重载+运算符
    // Person operator+(Person &p)
    // {
    //     Person temp;
    //     temp.m_A = this->m_A + p.m_A; // 这里this代表p1，p代表p2
    //     temp.m_B = this->m_B + p.m_B;
    //     return temp;
    // }
    int m_A;
    int m_B;
};

// 2. 通过全局函数重载+运算符
Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

// 函数重载的版本
Person operator+(Person &p1, int num)
{
    Person temp;
    temp.m_A = p1.m_A + num;
    temp.m_B = p1.m_B + num;
    return temp;
}

void test01()
{
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;
    // 成员函数重载本质调用
    // Person p3 = p1.operator+(p2); // 两个类对象相加，p2是传入的对象，p1是上边的this对应的对象
    Person p3 = p1 + p2; // 上式或下式的简化形式
    // 全局函数重载本质调用
    // Person p3 = operator+(p1, p2); // 传入两个Person实例化对象
    cout << "p3.m_A = " << p3.m_A << endl;
    cout << "p3.m_B = " << p3.m_B << endl;

    // 运算符重载也可以发生函数重载
    Person p4 = p1 + 100; // Person + int
    cout << "p4.m_A = " << p4.m_A << endl;
    cout << "p4.m_B = " << p4.m_B << endl;
}

int main() {
    test01();
    return 0;
}