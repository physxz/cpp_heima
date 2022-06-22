#include <iostream>
using namespace std;

class Person
{
public:
    void showClassName()
    {
        cout << "this is Person class" << endl;
    }
    void showPersonAge()
    {
        if (this == nullptr) // 为避免下面的错误，加上这两行判断一下来避免错误
            return;
        // 报错原因为传入的指针为空 m_Age此处等价于this->m_Age 但是this指向了空指针，所以报错
        cout << "age = " << m_Age << endl; // 只有这一行会报错
    }
    int m_Age;
};

void test01()
{
    Person *p = nullptr;
    p->showClassName(); // 正常
    p->showPersonAge(); // 错误，
}

int main() {
    test01();
    return 0;
}