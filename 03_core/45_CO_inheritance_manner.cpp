#include <iostream>
using namespace std;

class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1 : public Base1
{
public:
    void func()
    {
        m_A = 10; // 子类对父类的 公共权限 的成员继承的依然是 公共权限
        m_B = 10; // 子类对父类的 保护权限 的成员继承的依然是 公共权限
        // m_C = 10; // 子类对父类的 私有权限 的成员 访问不到
    }
};

class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son2 : protected Base2
{
public:
    void func()
    {
        m_A = 100; // 父类中 公共成员，到子类中变为 保护权限
        m_B = 100; // 父类中 保护成员，到子类中变为 保护权限
        // m_C = 100; // 父类中的私有成员 子类访问不到
    }
};

class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class Son3 : private Base3
{
public:
    void func()
    {
        m_A = 100; // 父类中公共成员，到子类中变为 私有成员
        m_B = 100; // 父类中保护成员，到子类中变为 私有成员
        // m_C = 100; // 父类中私有成员，不管用什么方式，子类都访问不到
    }
};

class GrandSon3 : public Son3
{
public:
    void func()
    {
        // m_A = 1000; // 到Son3中，m_A变为私有，即使是孙子也访问不到
        // m_B = 1000; // 到Son3中，m_A变为私有，即使是孙子也访问不到
    }
};

void test01()
{
    Son1 s1;
    s1.m_A = 100; // 类外可以访问 公共权限 成员
    // s1.m_B = 100; // 类外访问不到 保护权限 成员
}
void test02()
{
    Son2 s1;
    // s1.m_A = 1000; // 父类中虽然是公共权限，但子类中是保护权限，类外无法访问
    // s1.m_B = 1000; // 在子类中为保护权限，访问不到
}
void test03()
{
    Son3 s1;
    // s1.m_A = 1000; // 到Son3中变为私有成员，类外访问不到
    // s1.m_B = 1000; // 到Son3中变为私有成员，类外访问不到
}

int main() {
    test01();
    test02();
    test03();
    return 0;
}