/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 10:39:55
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 11:21:18
 * @FilePath: /17_array_backwards.cpp
 * @Description: ×××××××××数组逆置××××××××××
 */
#include <iostream>
using namespace std;

int main() {
    // 1.创建数组
    int arr[5] = {1,2,3,4,5};
    cout << "数组逆置后：";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    // 2.实现逆置
    // 2.1记录起始下标位置
    // 2.2记录结束下标位置
    // 2.3起始下标与结束下标的元素互换
    // 2.4起始位置++ 结束位置--
    // 2.5循环执行2.1操作，直到起始位置>=结束位置
    int start = 0;
    int end = sizeof(arr)/sizeof(arr[start]) - 1;
    while (start <= end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; end--;
    }
    // 3.打印逆置数组
    cout << "数组逆置后：";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}