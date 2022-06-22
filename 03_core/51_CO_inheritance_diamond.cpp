#include <iostream>
using namespace std;

// 动物类
class Animal
{
public:
    int m_Age;
};

// 利用虚继承可以解决菱形继承的问题，在继承方式之间加关键字virtual变为虚继承
// Animal类变为 虚基类
// 羊类
class Sheep : virtual public Animal {};
// 驼类
class Camel : virtual public Animal {};

//羊驼类
class Alpaca : public Sheep, public Camel {};

void test01()
{
    Alpaca a;
    a.Sheep::m_Age = 18;
    a.Camel::m_Age = 28;
    // 当菱形继承时，两个父类拥有相同数据，需要加以作用域区分
    cout << "a.Sheep::m_Age = " << a.Sheep::m_Age << endl;
    cout << "a.Camel::m_Age = " << a.Camel::m_Age << endl;
    cout << "a.m_Age = " << a.m_Age << endl;
    // 这份数据我们知道只要有一份就可以了，菱形继承导致数据有两份，资源浪费

}

int main() {
    test01();
    return 0;
}