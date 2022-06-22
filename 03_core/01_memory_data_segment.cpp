/*
 * @Author: 赵小鑫
 * @Date: 2022-05-07 23:42:18
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 00:37:24
 * @FilePath: /03_core/01_memory_data_segment.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

// 全局变量
int g_a = 10;
int g_b = 10;
// const修饰的全局变量，全局常量
const int c_g_a = 10;
const int c_g_b = 10;

int main() {
    // 全局变量、静态变量、常量
    // 创建局部变量
    int a = 10;
    int b = 10;
    cout << "局部变量a的地址为：\t" << &a << endl;
    cout << "局部变量b的地址为：\t" << &b << endl;

    cout << "全局变量g_a的地址为：\t" << &g_a << endl;
    cout << "全局变量g_b的地址为：\t" << &g_b << endl;

    // 静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a的地址为：\t" << &s_a << endl;
    cout << "静态变量s_b的地址为：\t" << &s_b << endl;

    // 常量
    // 字符串常量
    cout << "字符串常量1的地址为：\t" << &("hello world") << endl;
    cout << "字符串常量2的地址为：\t" << &("hello") << endl;
    
    // const修饰的变量
    // const修饰的全局变量
    cout << "全局常量c_g_a的地址为：\t" << &c_g_a << endl;
    cout << "全局常量c_g_b的地址为：\t" << &c_g_b << endl;

    // const修饰的局部变量
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "局部常量c_l_a的地址为：\t" << &c_l_a << endl;
    cout << "局部常量c_l_b的地址为：\t" << &c_l_b << endl;

    return 0;
}