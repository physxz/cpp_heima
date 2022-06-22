/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 15:34:58
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 15:42:02
 * @FilePath: /20_func_parameter.cpp
 * @Description: 值传递
 */
#include <iostream>
using namespace std;

void swap(int num1, int num2) {
    cout << "交换前：" << num1 << endl;
    cout << "交换前：" << num2 << endl;
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "交换后：" << num1 << endl;
    cout << "交换后：" << num2 << endl;
    // return; // 返回值不需要时可以不写return
}

int main() {
    int a = 10;
    int b = 20;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // 当值传递时，函数的形参发生改变，并不会影响实参
    swap(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}