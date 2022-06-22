#include <iostream>
using namespace std;

class MyInterger
{
    friend ostream & operator<<(ostream &cout, MyInterger myint);
public:
    MyInterger()
    {
        m_Num = 0;
    }
    // 重载前置++运算符；返回引用是为了一直对一个数据进行递增操作
    MyInterger & operator++()
    {
        // 先进行++运算
        m_Num++;
        // 再将自身做返回
        return *this;
    }
    // 重载后置++运算符
    MyInterger operator++(int) // 用int作占位参数，避免函数重载冲突，可以用于区分前置和后置递增
    {
        // 先记录当时结果
        MyInterger temp = *this;
        // 后递增
        m_Num++;
        // 最后将记录的结果做返回
        return temp;
    }
private:
    int m_Num;
};

// 全局函数重载<<云运算符
// 这里myint不加引用是因为后置++运行的局部变量，结束就释放掉了，用&就指向空内存了
ostream & operator<<(ostream &cout, MyInterger myint)
{
    cout << myint.m_Num;
    return cout;
}

void test01()
{
    MyInterger myint;
    cout << ++(++myint) << endl;
    cout << myint << endl;
}

void test02(){
    MyInterger myint;
    cout << myint++ << endl;
    cout << myint << endl;
}

int main() {
    // test01();
    // int a = 0;
    // cout << ++(++a) << endl;
    // cout << a << endl;
    test02();
    return 0;
}