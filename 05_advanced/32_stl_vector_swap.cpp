#include <iostream>
#include <vector>
using namespace std;

/*
vector互换容器
- swap(vec); // 将vec与本身的元素互换
*/

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 1.基本使用
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "交换前：" << endl;
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    cout << "交换后：" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

// 2.实际用途
// 巧用swap可以收缩内存空间
void test02()
{
    vector<int> v;
    for (size_t i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的容大小：" << v.size() << endl;

    v.resize(3); // 重新指定大小
    cout << "v的容量为：" << v.capacity() << endl; // 重新指定大小后容量不会变化，有时会浪费内存空间
    cout << "v的容大小：" << v.size() << endl;

    // 巧用swap收缩内存空间
    vector<int> (v).swap(v);
    // vector<int> (v) 以值传递的方式传v对象到一个相同类型的匿名对象(x)中，属于隐式转换法(x=v)，
    // 这里会触发拷贝构造。当匿名对象没有进行绑定操作，会自动进行析构
    // 等价于一下两行代码
    // vector<int> x(v); // 等价于 vector<int> x = v; v的大小为3，容量为10多万，拷贝构造后 x的大小为3，容量也为3
    // x.swap(v); // 容器交换后v的大小变为3，容量也变为3
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的容大小：" << v.size() << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}