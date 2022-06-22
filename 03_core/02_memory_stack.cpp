/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 00:45:40
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 00:52:19
 * @FilePath: /02_memory_stack.cpp
 * @Description: 
 */
#include <iostream>
using namespace std;

int * func(int b) { // 形参数据也会放在栈区
    b = 100;
    int a = 10; // 局部变量，存放在栈区，栈区的数据在函数执行完成后自动释放
    return &a;  
}

int main() {
    int *p = func(1);
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}