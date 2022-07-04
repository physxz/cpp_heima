#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
队列queue常用接口
构造函数
- queue<T> que; // queue采用模板类实现，queue对象的默认构造形式
- queue(const queue &que); // 拷贝构造
赋值操作
- queue & operator=(const queue &que); // 重载=操作符
数据存取
- push(elem); // 往队尾添加元素
- pop(); // 从队头移除第一个元素
- back(); // 返回最后一个元素
- front(); // 返回第一个元素
大小操作
empty(); // 判断堆栈是否为空
size(); // 返回栈的大小
*/

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
    // 创建队列
    queue<Person> q;

    // 准备数据
    Person p1("唐僧", 30);
    Person p2("孙悟空", 1000);
    Person p3("猪八戒", 900);
    Person p4("沙僧", 800);
    
    // 入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    
    cout << "队列大小为：" << q.size() << endl;

    // 只要队列不为空，查看队头，查看队尾，出队
    while ( !q.empty() )
    {
        // 查看队头
        cout << "队头元素 --- 姓名：" << q.front().m_Name << " "
             << "年龄：" << q.front().m_Age << endl;
        // 查看队尾
        cout << "队尾元素 --- 姓名：" << q.back().m_Name << " "
             << "年龄：" << q.back().m_Age << endl;
        // 出队
        cout << "------" << endl;
        q.pop();
    }
    cout << "队列大小为：" << q.size() << endl;
}

int main()
{
    test01();
    return 0;
}