#include <iostream>
using namespace std;

class Animal
{
public:
    // 虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat: public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

class Dog: public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};

// 地址早绑定，在编译阶段确定函数地址
// 如果想执行猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定

// 动态多态满足条件
// 1. 有继承关系
// 2. 子类重写(函数返回值类型、函数名、参数列表完全相同)父类的虚函数

// 动态多态使用
// 父类的指针或者引用指向子类对象
void doSpeak(Animal &animal) // Animal &animal = cat;
{
    animal.speak(); // 该函数是虚函数，传入的参数并不能立马确定是属于什么类，需要去找到底是哪一个子类
}

void test01()
{
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}

void test02()
{
    cout << "sizeof Animal: " << sizeof(Animal) << endl; // 没有virtual大小为1(空类),有virtual大小为8(指针)
    cout << "pointer: " << sizeof(int *) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}