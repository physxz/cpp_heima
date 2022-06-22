/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 10:23:39
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 10:37:05
 * @FilePath: /16_array_1d.cpp
 * @Description: 五只小猪找出最重的
 */

#include <iostream>
using namespace std;

int main() {
    int arr[5] = {300,350,200,400,250};
    int max = arr[0];
    for (int i = 0; i < 5; i++)
        if (max < arr[i])
            max = arr[i];
    cout << "最重的小猪体重为：" << max << endl;
    return 0;
}