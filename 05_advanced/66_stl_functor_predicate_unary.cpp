#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 仿函数返回值类型是bool数据类型，称为谓词
// 一元谓词

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 查找容器中有没有大于5的数字
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive()); // GreaterFive()匿名函数对象
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到了大于5的数字：" << *it << endl;
    }
}

int main()
{
    test01();
    return 0;
}