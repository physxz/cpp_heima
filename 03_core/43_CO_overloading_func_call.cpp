#include <iostream>
#include <string>
using namespace std;

class MyPrint
{
public:
    void operator()(string test)
    {
        cout << test << endl;
    }
};

void MyPrint02(string test)
{
    cout << test << endl;
}

void test01()
{
    MyPrint myPrint;
    myPrint("Hello World"); // 由于使用起来非常类似于函数调用，因此函数调用运算符重载称为仿函数
    MyPrint02("Hello World");
}

// 仿函数非常灵活，没有固定写法
class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test02()
{
    MyAdd myAdd;
    int ret = myAdd(100, 100);
    cout << "ret = " << ret << endl;

    // 匿名函数对象；MyAdd()()等价于myAdd()
    cout << MyAdd()(100,100) << endl; // 当前行结束后立即释放
}

int main() {
    test01();
    test02();
    return 0;
}