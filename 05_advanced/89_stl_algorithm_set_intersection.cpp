#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 常用集合算法 set_intersection 交集
// 注意：两个集合必须是有序序列

void myPrint(int &val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> vTarget;
    
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    // 目标容器需要提前开辟空间
    // 最特殊情况，大容器包含小容器，开辟空间，取最小容器的size即可
    vTarget.resize(min(v1.size(), v2.size()));
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    // for_each(vTarget.begin(), vTarget.end(), myPrint); // 5 6 7 8 9 0 0 0 0 0
    for_each(vTarget.begin(), itEnd, myPrint); // 5 6 7 8 9
    cout << endl;
}

int main()
{
    test01();
    return 0;
}