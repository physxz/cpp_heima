/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 05:59:25
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 06:08:19
 * @FilePath: /12_func_.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

// 占位参数可以有默认值
void func(int a, int = 10) {
    cout << "This is a func." << endl;
}

int main() {
    func(10); // 因为第二个参数有默认值，只需传一个参数
    return 0;
}