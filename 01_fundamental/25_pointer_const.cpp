/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 19:44:46
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 19:56:48
 * @FilePath: /25_pointer_const.cpp
 * @Description: 
 */
#include <iostream>
using namespace std;

int main() {
    // 1.const修饰变量
    int a = 10;
    int b = 20;
    const int *p = &a;  // 常量指针
    // *p = 30;  // 错误，指针指向的值不可以可变
    p = &b;  // 正确，指针的指向可以改变
    
    // 2.const修饰指针
    int *const p2 = &a;
    *p2 = 100;  // 正确，指针指向的值可以改变
    // p2 = &b;  // 错误，指针的指向不可以改变

    // 3.const即修饰变量又修饰指针
    const int *const p3 = &a;
    // *p3 = 500;  // 错误
    // p3 = &b;  // 错误
    return 0;
}