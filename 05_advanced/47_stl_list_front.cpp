#include <iostream>
#include <list>
using namespace std;

/*
list数据存取
链表不支持随机访问，所以没有下标或at方式访问
*/

void test01()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    // l1[0]; // 不可以用[]访问list容器中的元素
    // l1.at(0); // 不可以用at方式访问list容器中的元素
    // 原因是list本质上是链表，不是用连续线性空间存储数据(每个结点的地址可能不连续)，迭代器也是不支持随机访问的

    cout << "第一个元素：" << l1.front() << endl;
    cout << "最后一个元素：" << l1.back() << endl;

    // 验证迭代器是不支持随机访问的
    list<int>::iterator it = l1.begin();
    it++;
    it--; // 支持双向
    // it = it + 1; // 不支持随机访问
    // 因为链表地址不连续，所以不能用直接加几的方式访问list容器；it++支持，是因为内部重载了++运算符
}

int main()
{
    test01();
    return 0;
}