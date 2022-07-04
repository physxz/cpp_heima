#include <iostream>
#include <deque>
using namespace std;

/*
deque插入和删除
两端插入
- push_back(elem); // 尾插
- push_front(elem); // 头插
- pop_back(); // 尾删
- pop_front(); // 头删
指定位置
- insert(pos, elem); // 在pos位置插入一个elem元素的拷贝，返回新数据的位置
- insert(pos, n, elem); // 在pos位置插入n个elem数据，无返回值
- insert(pos, beg, end); // 在pos位置插入[beg, end)区间的数据，无返回值
- clear(); // 情况容器的所有数据
- erase(beg, end); // 删除[beg, end)区间的数据，返回下一个数据的位置
- erase(pos); // 删除pos位置的数据，返回下一个数据的位置
*/

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 两端操作
void test01()
{
    deque<int> d1;
    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    // 头插
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1); // 200 100 10 20

    // 尾删
    d1.pop_back();
    printDeque(d1); // 200 100 10

    // 头删
    d1.pop_front();
    printDeque(d1); // 100 10
}

// 指定位置
void test02()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1); // 200 100 10

    // insert插入
    d1.insert(d1.begin(), 1000); // 第一个元素时迭代器
    printDeque(d1);

    d1.insert(d1.begin(), 2, 10000);
    printDeque(d1);

    // 按区间进行插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end()); // 在d1.begin()处插入d2.begin()-d2.end()区间内的数据
    printDeque(d1);
}

void test03()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    // 删除
    deque<int>::iterator it = d1.begin(); // 200 100 10 20
    it++; // 迭代器向后偏移1
    d1.erase(it);
    printDeque(d1); // 200 10 20

    // 按区间方式删除
    // d1.erase(d1.begin(), d1.end()); // 等价于d1.clear();
    d1.clear();
    printDeque(d1);
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}