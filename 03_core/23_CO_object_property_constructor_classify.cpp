#include <iostream>
using namespace std;

class Person
{
public:
    // 按参数分类 有参构造和无参构造(默认构造)
    Person()
    {
        cout << "Person的无参构造函数调用" << endl;
    }
    Person(int a)
    {
        age = a;
        cout << "Person的有参构造函数调用" << endl;
    }
    // 按类型分类 普通构造和拷贝构造
    Person(const Person &p)
    {
        age = p.age; // 将传入的人身上的所有属性，拷贝到我身上
        cout << "Person的拷贝构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
    int age;
};

void test01()
{
    // 1. 括号法
    Person p1;     // 默认构造函数的调用
    Person p2(10); // 有参构造函数调用
    Person p3(p2); // 拷贝构造函数调用
    // 注意事项1
    // 调用默认构造函数时不要加()
    // Person p1(); // 错误，编译器会认为是一个函数的声明而不是创建对象
    void func(); // 函数声明
    // cout << "p2的年龄为" << p2.age << endl;
    // cout << "p3的年龄为" << p3.age << endl;

    // 2. 显式法
    Person p4;
    Person p5 = Person(10); // 有参构造
    Person p6 = Person(p2); // 拷贝构造

    Person(10); // 匿名对象 特点：当前一行执行结束后，系统会立即回收匿名对象
    cout << "aaaaaa" << endl; // 上一行调用析构后才会打印这一行
    
    // 注意事项2
    // 不要利用拷贝构造函数 初始化匿名对象，编译器会认为是对象的声明
    // Person(p4); // 错误，重定义，编译器会认为Person(p3)等价于Person p3;
    
    // 3. 隐式转换法
    Person p7 = 10; // 有参构造，相当于Person p7 = Person(10);
    Person p8 = p4; // 拷贝构造
}

int main() {
    test01();
    return 0;
}