/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 17:34:00
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 17:44:20
 * @FilePath: /24_pointer_null.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

int main() {
    // 1.空指针
    // 1.1空指针用于给指针变量初始化
    int *p = nullptr;
    // 1.2空指针是不可以访问的
    // *p = 100;   // 无权限访问，报错：段错误 (核心已转储)
    // 0-255之间的内存编号是系统占用的，因此不可访问
    // 2.野指针
    int *p2 = (int *)0x11110000; // 无权限访问，报错：段错误 (核心已转储)
    cout << *p2 << endl;
    return 0;
}