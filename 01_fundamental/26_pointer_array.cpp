/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 19:59:55
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 20:09:36
 * @FilePath: /26_pointer_array.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "第1个元素为：" << arr[0] << endl;
    int *p = arr; // arr就是数组的首地址
    cout << "利用指针访问第1个元素：" << *p << endl;
    p++; // 让指针向后偏移4个字节，即1个元素
    cout << "利用指针访问第1个元素：" << *p << endl;
    cout << "利用指针遍历数组：";
    for (int *p2 = arr; p2 < &arr[10]; p2++)
        cout << *p2 << " ";
    cout << endl;
    return 0;
}