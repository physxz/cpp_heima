#include <iostream>
#include <string>
#include <list>
using namespace std;

// list容器 排序案例，对自定义数据类型排序
// 按照年龄进行升序，如果年龄相同按照身高进行降序

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }
    string m_Name;
    int m_Age;
    int m_Height;
};

void printPerson(const list<Person> &l)
{
    for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "姓名：" << it->m_Name << "\t"
             << "年龄：" << it->m_Age << "\t"
             << "身高：" << it->m_Height << endl;
    }
}

// 指定排序规则
bool comparePerson(Person &p1, Person &p2)
{
    // 按照年龄 升序
    if (p1.m_Age == p2.m_Age)
    {
        // 年龄相同，按照身高降序
        return p1.m_Height > p2.m_Height;
    }
    else
    {
        return p1.m_Age < p2.m_Age;
    }
}

void test01()
{
    // 创建容器
    list<Person> l;

    // 实例化对象
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    // 插入数据
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);

    printPerson(l);
    
    // 排序
    cout << "-------------排序后--------------" << endl;
    l.sort(comparePerson);
    printPerson(l);
}

int main()
{
    test01();
    return 0;
}