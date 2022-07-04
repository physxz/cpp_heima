#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// list容器反转和排序

void printList(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    list<int> l1;
    l1.push_back(20);
    l1.push_back(10);
    l1.push_back(50);
    l1.push_back(40);
    l1.push_back(30);
    
    cout << "反转前：" << endl;
    printList(l1);

    // 反转
    l1.reverse();
    cout << "反转后：" << endl;
    printList(l1);
}

bool myCompare(int v1, int v2)
{
    // 降序，就让第一个数大于第二个数
    return v1 > v2;
}

// 排序
void test02()
{
    list<int> l1;
    l1.push_back(20);
    l1.push_back(10);
    l1.push_back(50);
    l1.push_back(40);
    l1.push_back(30);

    cout << "排序前：" << endl;
    printList(l1);

    // 所有不支持随机访问迭代器的容器，不可以用标准算法
    // 不支持随机访问迭代器的容器，内部会提供一些对应算法
    // sort(l1.begin(), l1.end()); // 这里的sort是全局函数
    l1.sort(); // 这里的sort是list自己的成员函数，默认排序规则从小到大，升序
    cout << "排序后：" << endl;
    printList(l1);

    l1.sort(myCompare);
    printList(l1);
}

int main()
{
    // test01();
    test02();
    return 0;
}