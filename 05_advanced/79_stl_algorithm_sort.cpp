#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 常用排序算法 sort

void myPrint(int &val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    cout << "排序前" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    // 升序
    cout << "升序" << endl;
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    // 降序
    cout << "降序" << endl;
    sort(v.begin(), v.end(), greater<int>()); // 需要包含functional头文件
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();
    return 0;
}