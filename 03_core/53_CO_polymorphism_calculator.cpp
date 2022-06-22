#include <iostream>
#include <string>
using namespace std;

class Calculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+")
            return m_Num1 + m_Num2;
        else if (oper == "-")
            return m_Num1 - m_Num2;
        else if (oper == "*")
            return m_Num1 * m_Num2;
        // 如果想要扩展新的功能，需要修改源代码，太麻烦
        // 在真实的开发中，提倡开闭原则：对扩展进行开放，对修改进行关闭
    }
    int m_Num1;
    int m_Num2;
};

// 利用多态实现计算器
// 实现计算器的基类(抽象类)
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

// 加法计算器类
class AddCalculator: public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

// 减法计算器类
class SubCalculator: public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

class MultCalculator: public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test02()
{
    // 多态使用条件
    // 父类指针或引用指向子类对象

    // 加法运算
    AbstractCalculator *abc = new AddCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;

    // 减法运算
    abc = new SubCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;

    // 乘法运算
    abc = new MultCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;
}

void test01()
{
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;
    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
    cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
    cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}