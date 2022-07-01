#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// vector容器存放内置数据类型

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    // 创建vector容器，可以将其看做数组
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 第1种遍历方式
    // 通过迭代器访问容器中的数据
    // vector<int>::iterator itBegin = v.begin(); // 起始迭代器，指向容器中第一个迭代器
    // vector<int>::iterator itEnd = v.end(); // 结束迭代器，指向容器中最后一个元素的下一个位置
    
    // while (itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }
    
    // 第2种遍历方式
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    
    // 第3种遍历方式
    for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test01();
    return 0;
}