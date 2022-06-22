/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 01:54:49
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 02:05:15
 * @FilePath: /06_reference_alias2.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

int main() {
    // 1. 引用必须初始化
    int a = 10;
    // int &b; // 报错
    int &b = a;

    // 2. 引用一旦初始化后，就不可更改了
    int c = 20;
    b = c; // 这是赋值操作，不是更改引用
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    // int &b = c; // 错误，b重复定义
    return 0;
}