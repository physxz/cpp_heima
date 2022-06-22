/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 11:22:17
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 14:57:31
 * @FilePath: /18_array_bubble_sort.cpp
 * @Description: 冒泡排序
 */
#include <iostream>
using namespace std;

int main() {
    int arr[9] = {4,2,8,0,5,7,1,3,9};
    cout << "排序后：";
    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";
    cout << endl;
    // 排序总轮数：元素个数-1 外层一次内层一周
    for (int i = 0; i < 9-1; i++) {
        // 每轮对比次数：元素个数-排序轮数-1 外层执行一次，内层将一个数从头比较到尾
        for (int j = 0; j < 9-i-1; j++) {
            // 如果第一个数字大于第二个数字，交换两个数字
            if (arr[j] > arr[j+1]) {
                int temp = 0;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "排序后：";
    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}