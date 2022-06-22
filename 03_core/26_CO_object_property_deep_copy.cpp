#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person的默认构造函数调用" << endl;
    }
    Person(int age, int height)
    {
        m_Age = age;
        m_Height = new int(height);
        cout << "Person的默认构造函数调用" << endl;
    }
    Person(const Person &p)
    {
        cout << "Person的拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
        // m_Height = p.m_Height; // 浅拷贝，编译器默认实现的就是这行代码
        // 深拷贝操作 就是另辟空间存储拷贝的值
        m_Height = new int(*p.m_Height);
    }
    ~Person()
    {
        // 析构将堆区开辟数据做释放操作
        if (m_Height != nullptr)
        {
            delete m_Height;
            m_Height = nullptr; // 防止野指针出现，置空
        }
        cout << "Person的析构函数调用" << endl;
    }
    int m_Age;
    int *m_Height;
};

void test01()
{
    Person p1(18, 160);
    cout << "p1的年龄为" << p1.m_Age << "\t"
         << "p1的身高为" << *p1.m_Height << endl;
    Person p2(p1);
    cout << "p2的年龄为" << p2.m_Age << "\t"
         << "p2的身高为" << *p2.m_Height << endl;
}

int main() {
    test01();
    return 0;
}