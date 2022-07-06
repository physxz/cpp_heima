#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 常用算术生成算法 accumulate

void test01()
{
    vector<int> v;

    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }

    int total = accumulate(v.begin(), v.end(), 1000); // 参数3是起始累加值
    cout << "total = " << total << endl;
}

int main()
{
    test01();
    return 0;
}