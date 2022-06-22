/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 05:43:38
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 05:55:43
 * @FilePath: /11_func_default_parameter.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

int func(int a, int b = 20, int c = 30) {
    return a+b+c;
}

// 1. 如果某个位置已经有了默认参数，那么从这个位置开始往后
//    从左到右都必须有默认值
// int func2(int a, int b = 20, int c = 0) { // 错误
    // return a+b+c;
// }

// 2. 如果函数声明有默认参数，函数实现就不能有默认参数
//    声明和实现只能有一个有默认参数

int func2(int a, int b);
// int func2(int a = 20, int b = 20) { // 错误，二异性
int func2(int a = 10, int b = 10) {
    return a+b;
}

int main() {
    cout << func(10,20,30) << endl;
    cout << func(10) << endl;
    cout << func(10,30) << endl;
    cout << func2(10,10) << endl;
    return 0;
}