/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 21:41:27
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 22:13:12
 * @FilePath: /28_pointer_array_func.cpp
 * @Description: 利用冒泡排序，实现对整型数组的升序排列
 */

#include <iostream>
using namespace std;

// 冒泡排序函数 参数1：数组首地址 参数2：数组长度
void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (*(arr+j) > *(arr+j+1)) {
                int temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}

// 打印数组
void printArray(int *arr, int len) {
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // 1.创建数组
    // 2.创建函数，实现冒泡排序
    // 3.打印排序后的数组
    int arr[10] = {4,3,6,9,1,2,10,8,7,5};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "排序前：";
    printArray(arr, len);
    bubbleSort(arr, len);
    cout << "排序后：";
    printArray(arr, len);
    return 0;
}