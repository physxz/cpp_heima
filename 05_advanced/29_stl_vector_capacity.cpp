#include <iostream>
#include <vector>
using namespace std;

/*
vector容量和大小
- empty(); // 判断容器是否为空
- capacity(); // 容器的容量
- size(); // 返回容器中元素的个数
- resize(int num); // 重新指定容器的长度(大小)为num，若容器边长，则以默认值填充新位置
                   // 如果容器变短，则末尾超出容器长度的元素被删除
- resize(int num, elem); // 重新指定容器的长度(大小)为num，若容器边长，则以elem填充新位置
                         // 如果容器变短，则末尾超出容器长度的元素被删除
*/

void printVector(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    if (v1.empty())
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量为：" << v1.capacity() << endl;
        cout << "v1的大小为：" << v1.size() << endl;
    }
    v1.resize(15, 100); // 利用重载版本，可以指定默认填充值(参数2)
    printVector(v1);
    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl;
    v1.resize(5); // 如果重新制定的比原来的短，超出部分会被删除
    printVector(v1);
    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl;
}

int main()
{
    test01();
    return 0;
}