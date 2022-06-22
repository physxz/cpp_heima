/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 17:01:53
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 17:07:02
 * @FilePath: /22_pointer_define.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

int main() {
    // 1.定义指针
    int a = 10;
    int *p;
    p = &a;
    cout << "a的地址为：" << &a << endl;
    cout << "指针p为：" << p << endl;
    // 2.使用指针 通过解引用*的方式找到指针指向的内存地址
    *p = 1000;
    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;
    return 0;
}