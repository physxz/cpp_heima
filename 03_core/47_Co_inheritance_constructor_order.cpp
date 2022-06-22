#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base构造函数！" << endl;
    }
    ~Base()
    {
        cout << "Base析构函数！" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son构造函数！" << endl;
    }
    ~Son()
    {
        cout << "Son析构函数！" << endl;
    }
};

void test01()
{
    // Base b;
    Son s; // Base构造->Son构造->Son析构->Base析构
}

int main() {
    test01();
    return 0;
}