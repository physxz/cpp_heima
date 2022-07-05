#include <iostream>
using namespace std;

// 函数对象使用(仿函数)

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

// 1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01()
{
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}

// 2.函数对象超出普通对象的概念，函数对象可以有自己的状态
class MyPrint
{
public:
    MyPrint() // 构造函数只在创建对象时调用构造函数
    {
        this->count = 0;
    }
    void operator()(string test)
    {
        cout << test << endl;
        count++;
    }

    int count; // 记录内部自己状态
};

void test02()
{
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");

    cout << "MyPrint调用次数为：" << myPrint.count << endl;
}

// 3.函数对象可以作为参数传递
void doPrint(MyPrint &mp, string test)
{
    mp(test);
}

void test03()
{
    MyPrint myPrint;
    doPrint(myPrint, "hello c++");
}

int main()
{
    // test01();
    test02();
    test03();
    return 0;
}