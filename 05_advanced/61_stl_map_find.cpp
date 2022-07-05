#include <iostream>
#include <map>
using namespace std;

// map查找和统计

void test01()
{
    map<int, int> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(3, 30));

    // 查找 find返回的是迭代器
    map<int, int>::iterator pos = m.find(3);
    if (pos != m.end())
    {
        cout << "找到该元素" << endl;
        cout << "key = " << pos->first << "\t" << "value = " << pos->second << endl;
    }
    else
    {
        cout << "未找到该元素" << endl;
    }

    // 统计
    // map不允许插入重复key元素，count结果只有0或1
    // multimap的count统计可以大于1
    int num = m.count(3);
    cout << "num = " << num << endl;
}

int main()
{
    test01();
    return 0;
}