#include <iostream>
using namespace std;

class Person
{
    friend ostream & operator<<(ostream &cout, Person &p); // 友元，使得该全局函数可以访问类的私有成员
public:
    Person(int a, int b)
    {
        m_A = a;
        m_B = b;
    }
private:
    // 利用成员函数重载左移运算符 p.operator<<(cout) 简化后 p << cout
    // 通常不会利用成员函数重载<<运算符，因为无法实现cout在左侧
    // void operator<<(cout)
    // {

    // }
    int m_A;
    int m_B;
};

// 只能利用全局函数重载<<运算符
// ostream只能有一个，所以用引用
ostream & operator<<(ostream &out, Person &p) // 本质operator<<(cout, p) 简化 cout << p
{
    out << "m_A = " << p.m_A << " " << "m_B = " << p.m_B;
    return out; // out是cout的一个别名，指向的都是cout的内存空间，整个过程中只有一个内存存储
}

void test01()
{
    Person p(10,10);
    // p.m_A = 10;
    // p.m_B = 10;
    cout << p << endl << "Hello World" << endl; // 链式编程思想
    // 通过调用全局函数重载会返回cout，然后再调用全局函数重载再继续返回cout....
}

int main() {
    test01();
    return 0;
}