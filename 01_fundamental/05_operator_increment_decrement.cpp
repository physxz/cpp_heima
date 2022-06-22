/*
 * @Author: 赵小鑫
 * @Date: 2022-05-04 16:27:19
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-04 23:42:26
 * @FilePath: /05_operator_increment_decrement.cpp
 * @Description: 前置后置递增区别
 */

#include <iostream>
using namespace std;

int main() {
    // 1.前置递增
    int a = 10;
    ++a;
    cout << "a = " << a << endl;
    // 2.后置递增
    int b = 10;
    b++;
    cout << "b = " << b << endl;
    // 3.前置和后置的区别
    // 前置递增 先让变量加1，然后进行表达式运算
    int a2 = 10;
    int b2 = ++a2 * 10;
    cout << "a2 = " << a2 << endl;
    cout << "b2 = " << b2 << endl;
    // 后置递增 先进行表达式运算，然后让变量加1
    int a3 = 10;
    int b3 = a3++ * 10;
    cout << "a3 = " << a3 << endl;
    cout << "b3 = " << b3 << endl;
    return 0;
}