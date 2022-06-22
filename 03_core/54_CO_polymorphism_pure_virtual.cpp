#include <iostream>
using namespace std;

class Base
{
public:
    // 纯虚函数
    // 一个类只要有一个纯虚函数，这个类就成为抽象类
    // 抽象类特点
    // 1. 无法实例化对象
    // 2. 抽象类的子类，必须要重写父类中的纯虚函数，否则也属于抽象类，无法实例化对象
    virtual void func() = 0;
};

class Son: public Base
{
public:
    virtual void func()
    {
        cout << "function函数调用" << endl;
    }
};

void test01()
{
    // Base b; // 栈区，不允许使用抽象类类型 "Base" 的对象; 抽象类无法实例化对象
    // new Base; // 堆区，不允许使用抽象类类型 "Base" 的对象; 抽象类法无实例化对象
    Son s; // 如果Son没有重写父类中的纯虚函数，因此也属于抽象类，而抽象类无法实例化对象，因此会报错
    Base *base = new Son;
    base->func();
}

int main() {
    test01();
    return 0;
}