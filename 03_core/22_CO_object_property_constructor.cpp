#include <iostream>
using namespace std;

// 对象的初始化和清理
class Person
{
public:
    // 1 构造函数 在调用对象时会自动调用构造函数
    Person()
    {
        cout << "Person构造函数调用" << endl; // 编译器会空实现，就是没有这行代码
    }
    // 2. 析构函数 在对象销毁前自动调用析构函数
    ~Person()
    {
        cout << "Person析构函数调用" << endl;
    }
};

void test01()
{
    Person p; // 局部变量，是栈上的数据，test01执行完毕后会释放该对象
}

int main() {
    // Person p;
    test01();
    // getchar();
    return 0;
}