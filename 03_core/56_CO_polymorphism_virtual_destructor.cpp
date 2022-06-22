#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal构造函数调用" << endl;
    }

    // 虚析构
    // 利用虚析构可以解决父类指针释放子类对象时不干净的问题
    // virtual ~Animal() // 加virtual会走这一行代码，不加不会走
    // {
    //     cout << "Animal虚析构函数调用" << endl;
    // }

    // 纯虚析构 需要声明也需要实现
    // 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;

    // 纯虚函数
    virtual void speak() = 0;
};

// 纯虚析构
Animal::~Animal()
{
    cout << "Animal纯虚析构函数调用" << endl;
}


class Cat: public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat构造函数调用" << endl;
        m_Name = new string(name);
    }
    void speak()
    {
        cout << *m_Name << "小猫在说话" << endl;
    }
    string *m_Name;

    ~Cat()
    {
        if (m_Name != nullptr)
        {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = nullptr;
        }
    }
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    // 父类指针在析构时候，不会调用子类中析构函数，导致子类如果有堆区数据，那么会出现内存泄漏
    delete animal;
}

int main() {
    test01();
    return 0;
}