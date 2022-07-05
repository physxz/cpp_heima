#include <iostream>
#include <map>
using namespace std;

// map插入和删除

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << "\t" << "value = " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int> m;

    // 插入
    // 第一种方式
    m.insert(pair<int, int>(1, 10));
    // 第二种方式(更好用)
    m.insert(make_pair(2, 20));
    // 第三种方式
    m.insert(map<int, int>::value_type(3, 30));
    // 第四种方式 内部重载了[] 不建议使用
    m[4] = 40;

    // 不建议使用[]插入，用途：可以利用key访问到value
    // cout << m[4] << endl;

    printMap(m);

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3); // 按照key删除
    printMap(m);

    // 清空
    // m.erase(m.begin(), m.end());
    m.clear();
    printMap(m);
}

int main()
{
    test01();
    return 0;
}