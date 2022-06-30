#include <iostream>
using namespace std;

/**
 * 实现通用对数组进行排序的函数
 * 规则 从大到小
 * 算法 选择
 * 测试char数组，int数组
 **/

// 交换数组模板
template<typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 选择排序模板
template<typename T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        // for循环的作用是选择：选出最大值
        int max = i; // 选定的最大值下标(一般选第一个)
        for (int j = i+1; j < len; j++)
        {
            // 选定的最大值比比较得到的的数值要小，则最大值更新为比较得到的值，定位得到这一轮的最大值，但是还没有排序
            if (arr[max] < arr[j])
            {
                max = j; // 更新最大值
            }
        }
        // if语句的作用是排序：将每一轮的最大值置前
        if (max != i) // 如果比较得到的最大值与选定的最大值(第一个值)不相等，说明选定的在最大值并不是真正的最大值
        {
            // 交换选定的最大值和比较得到的最大值
            mySwap(arr[max], arr[i]);
        }
    }
}

// 打印数组模板
template<typename T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

// 测试char数组
void test01()
{
    char charArr[] = "badcfe";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num);
}

// 测试int数组
void test02()
{
    int intArr[] = {3,2,5,4,6,1};
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArray(intArr, num);
}

int main()
{
    test01();
    test02();
    return 0;
}