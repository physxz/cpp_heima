#include <iostream>
using namespace std;

// 如果我们写了有参构造函数，编译器就不在提供默认构造，但依然提供拷贝构造
class Person
{
public:
    // Person()
    // {
    //     cout << "Person的默认构造函数调用" << endl;
    // }
    Person(int age)
    {
        int m_Age = age;
        cout << "Person的有参构造函数调用" << endl;
    }
    // Person(const Person &p) // 注释掉后，编译器会自动生成拷贝构造函数
    // {
    //     m_Age = p.m_Age;
    //     cout << "Person的拷贝构造函数调用" << endl;
    // }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
    int m_Age;
};

// void test01()
// {
//     Person p;
//     p.m_Age = 18;
//     Person p2(p);
//     cout << "p2的年龄为" << p2.m_Age << endl;
// }

void test02()
{
    // Person p; // 错误，不存在默认构造函数
    Person p(28);
    Person p2(p);
    cout << "p2的年龄为" << p2.m_Age << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}