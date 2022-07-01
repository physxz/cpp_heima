#include <iostream>
#include <string>
#include <vector>
using namespace std;

// vector容器中存放自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    vector<Person> v;
    Person p1("孙悟空", 10);
    Person p2("猪八戒", 20);
    Person p3("沙和尚", 30);
    Person p4("唐三藏", 40);
    Person p5("二郎神", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍历容器中的数据
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl;
        cout << "1：姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
    }
}

// 存放自定义数据类型的指针
void test02()
{
    vector<Person*> v; // 保存实例化对象的地址，后面传递是需要加取址符&
    Person p1("孙悟空", 10);
    Person p2("猪八戒", 20);
    Person p3("沙和尚", 30);
    Person p4("唐三藏", 40);
    Person p5("二郎神", 40);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    // 遍历容器
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 传入的是地址，*it解出来的就是地址，要找到数据需要*(*it)或者使用->运算符
        // cout << "2：姓名：" << (*(*it)).m_Name << " 年龄：" << (*(*it)).m_Age << endl;
        cout << "2：姓名：" << (*it)->m_Name << " 年龄：" << (*it)->m_Age << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}