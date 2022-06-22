#include <iostream>
using namespace std;

// this指针
class Person
{
public:
    Person(int age)
    {
    // 1. 解决名称冲突
        // age = age; // 编译器认为前3个age是一回事
        // 三种解决办法
        // 1. 规范命名，成员变量最好以m_开头，有参构造函数的参数不加m_开头
        // m_Age = age;
        // 2. 限定作用域
        // Person::age = age;
        // 3. 加this指针
        this->age = age; // this指针指向被调用的成员函数所属的对象，即p1
    }
    Person & addAge(Person &p) // 返回引用值，不引用的话返回的是拷贝值，后续再操作针对的就是拷贝值而不是p2了，所以要引用
    {
        this->age += p.age;
        return *this; // 返回的是p2
    }

    int age; // 这里的age是另一回事(之前是写作m_Age)
};

void test01()
{
    Person p1(18);
    cout << "p1的年龄为" << p1.age << endl;
}

// 2. 返回对象本身用*this
void test02()
{
    Person p1(10);
    Person p2(10);
    // 链式编程思想
    p2.addAge(p1).addAge(p1).addAge(p1);
    cout << "p2的年龄为" << p2.age << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}