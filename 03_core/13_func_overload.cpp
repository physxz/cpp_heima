/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 06:12:34
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 06:28:35
 * @FilePath: /03_core/13_func_overload.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

// 函数重载：满足一定条件(能消除二异性即可)，函数名可以相同
// 1. 同一作用域下
void func() {
    cout << "func 的调用" << endl;
}
// 2.1 函数参数类型不同
void func(int a) {
    cout << "func (int) 的调用" << endl;
}
void func(double a) {
    cout << "func (double) 的调用" << endl;
}
// 2.2 函数参数个数不同
void func(int a, int b) {
    cout << "func (int a, int b) 的调用" << endl;
}
// 2.2 函数参数顺序不同
void func(int a, double b) {
    cout << "func (int a, double b)的调用" << endl;
}
void func(double a, int b) {
    cout << "func (double a, int b) 的调用" << endl;
}
// 注意：函数返回值无法作为函数重载的条件
// int func(double a, int b) { // 错误
//     cout << "func (double a, int b) 的调用" << endl;
//     return a+b;
// }

int main() {
    func();
    func(10);
    func(10.);
    func(10,20);
    func(10,20.);
    func(10.,20);
    return 0;
}