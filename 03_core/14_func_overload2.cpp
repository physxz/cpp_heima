/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 06:30:48
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 06:42:55
 * @FilePath: /14_func_overload2.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

// 函数重载的注意事项
// 1. 引用作为重载的条件
void func(int &a) { // int &a = 10; 不合法
    cout << "func(int &a) 调用" << endl;
}
void func(const int &a) { // const int &a = 10; 合法
    cout << "func(const int &a) 调用" << endl;
}

// 2. 函数重载碰到函数默认参数
void func2(int a, int b = 10) {
    cout << "func2(int a) 调用" << endl;
}
void func2(int a) {
    cout << "func2(int a) 调用" << endl;
}

int main() {
    // int a = 10;
    // func(a); // func(int &a) 调用
    // func(10); // func(const int &a) 调用
    // func2(10); // 函数重载碰到默认参数，易产生二异性
    func2(10,20);
    return 0;
}