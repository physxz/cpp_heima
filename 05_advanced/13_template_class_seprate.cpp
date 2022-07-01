#include <iostream>
#include <string>
using namespace std;
// 第一种解决方式，直接包含.cpp源文件，一般不用
// #include "13_person.cpp"

// 第二种解决方式(常用)，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件
#include "13_person.hpp"

// 类模板分文件编写问题及解决

// template<class T1, class T2>
// class Person
// {
// public:
//     Person(T1 name, T2 age);
//     void showPerson();
//     T1 m_Name;
//     T2 m_Age;
// };

// template<class T1, class T2>
// Person<T1, T2>::Person(T1 name, T2 age)
// {
//     this->m_Name = name;
//     this->m_Age = age;
// }

// template<class T1, class T2>
// void Person<T1, T2>::showPerson()
// {
//     cout << "姓名：" << this->m_Name << " "
//          << "年龄：" << this->m_Age << endl;
// }

void test01()
{
    Person<string, int> p("Jerry", 18);
    p.showPerson();
}

int main()
{
    test01();
    return 0;
}