#include <iostream>
#include <vector>
using namespace std;

/*
vector预留空间
- reserve(int len); // 容器预留len个元素长度，预留位置不初始化，元素不可访问
*/

void test01()
{
    vector<int> v;

    // 利用reserve预留空间
    v.reserve(100000);

    int num; // 统计开辟内存次数
    int *p = nullptr;

    clock_t start, end;
    start = clock();
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        // 每次动态扩展，都会变更地址，首地址就会发生变化
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "num = " << num << endl; // 预留前 num= 18，预留后 num=1
}

int main()
{
    test01();
    return 0;
}