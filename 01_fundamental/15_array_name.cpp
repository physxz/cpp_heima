/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 10:08:31
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 10:21:23
 * @FilePath: /15_array_1d.cpp
 * @Description: 数组名用途
 */

#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    // 查看数组所占内存空间
    cout << "整个数组所占内存空间：" << sizeof(arr) << endl;
    cout << "每个元素占用内存空间：" << sizeof(arr[0]) << endl;
    cout << "数组元素个数：" << sizeof(arr)/sizeof(arr[0]) << endl;
    // 查看数组内存地址
    cout << "数组首地址为：" << arr << endl;
    cout << "数组中第1个元素的地址：" << &arr[0] << endl;
    cout << "数组中第2个元素的地址：" << &arr[1] << endl;
    return 0;
}