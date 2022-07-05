#include <iostream>
#include <set>
using namespace std;

// set查找和统计
// find(key); // 查找key是否存在，若存在，返回其迭代器，若不存在，返回set.end();

// 查找
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    set<int>::iterator pos = s1.find(30);
    if (pos != s1.end())
    {
        cout << "找到该元素：" << *pos << endl;
    }
    else
    {
        cout << "未找到该元素" << endl;
    }
}

void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    
    // 统计30的个数
    int num = s1.count(30);
    // 对于set而言，统计结果要么是0要么是1，对于multiset而言是有用的
    cout << "num = " << num << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}