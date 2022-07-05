#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 二元谓词

class MyCompare
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    sort(v.begin(), v.end());

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 使用函数对象 改变算法策略，排序规则变为从大到小
    sort(v.begin(), v.end(), MyCompare()); // MyCompare()是匿名函数对象
    // 这一步相当于首先创建一个对象 MyCompare m;
    // 然后在sort中传入这个对象 sort(v.begin(), v.end(), m);

    cout << "----------------------" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test01();
    return 0;
}