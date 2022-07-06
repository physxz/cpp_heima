#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 常用集合算法 set_union

class MyPrint
{
public:
    void operator()(int &val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    vector<int> vTarget;
    
    // 目标容器提前开辟空间
    // 最特殊情况，两个集合完全没有重复元素，并集就是两个容器size相加
    vTarget.resize( v1.size() + v2.size() );

    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    // for_each(vTarget.begin(), vTarget.end(), MyPrint());
    for_each(vTarget.begin(), itEnd, MyPrint());
    cout << endl;
}

int main()
{
    test01();
    return 0;
}