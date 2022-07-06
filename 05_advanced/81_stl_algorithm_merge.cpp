#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 常用排序算法 merge
// 注意：两个容器必须是有序的，都是升序或者都是降序

void myPrint(int &val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);
    }

    // 目标容器
    vector<int> vTarget;
    // 目标容器提前开辟空间
    vTarget.resize(v1.size() + v2.size());

    // 升序
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), myPrint);
    cout << endl;

    // 降序
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin(), greater<int>());

    for_each(vTarget.begin(), vTarget.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();
    return 0;
}